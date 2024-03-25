/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:11 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 11:50:31 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
The function ft_get_input is used to parse and validate the command-line
arguments for the dining philosophers problem. It takes three arguments:
a pointer to a t_data structure representing the shared data of the simulation,
the count of command-line arguments, and an array of the command-line arguments.
*/
static bool	ft_get_input(t_data *data, int ac, char **av)
{
	if (ac < 5)
		return (ft_error(ERR_TOO_FEW_ARGS), RET_FALIURE);
	if (ac > 6)
		return (ft_error(ERR_TOO_MANY_ARGS), RET_FALIURE);
	data->nbr_of_philos = ft_atoi(av[1]);
	if (data->nbr_of_philos < 1)
		return (ft_error(ERR_PHILO), RET_FALIURE);
	data->time_to_die = ft_atoi(av[2]);
	if (data->time_to_die < 1)
		return (ft_error(ERR_ARG_TIME_TO_DIE), RET_FALIURE);
	data->time_to_eat = ft_atoi(av[3]);
	if (data->time_to_eat < 1)
		return (ft_error(ERR_ARG_TIME_TO_EAT), RET_FALIURE);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_sleep < 1)
		return (ft_error(ERR_ARG_TIME_TO_SLEEP), RET_FALIURE);
	data->meals_to_eat = -1;
	if (ac == 6)
	{
		data->meals_to_eat = ft_atoi(av[5]);
		if (data->meals_to_eat < 1)
			return (ft_error(ERR_ARG_EAT_LIMIT), RET_FALIURE);
	}
	return (RET_SUCCESS);
}

/*
The function `ft_init_data` is used to initialize the shared data for the
dining philosophers problem. It takes one argument: a pointer to a `t_data`
structure representing the shared data of the simulation.
*/
static bool	ft_init_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philos);
	if (!data->philos)
		return (ft_error(ERR_MALLOC), RET_FALIURE);
	data->thread = malloc(sizeof(pthread_t) * data->nbr_of_philos);
	if (!data->thread)
		return (free(data->philos), RET_FALIURE);
	data->mutex_forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philos);
	if (!data->mutex_forks)
		return (free(data->philos), free(data->thread), RET_FALIURE);
	data->exit = false;
	return (RET_SUCCESS);
}

/*
1.	It initializes a mutex for each fork in the simulation. The mutexes
	are stored in the `data->mutex_forks` array.
2.	It initializes a mutex for the exit condition (`data->mutex_exit`)
	and for the print operation (`data->mutex_printf`).
3.	It initializes each philosopher in the simulation. For each philosopher:
	- It sets the philosopher's ID to their index in the array plus one.
	- It sets the philosopher's eat count to zero.
	- It assigns the mutex for the philosopher's left fork and right fork.
	The right fork of philosopher `i` is the left fork of philosopher
	`i + 1`, with the last philosopher's right fork being the first
	philosopher's left fork.
	- It initializes a mutex for the philosopher's last meal time and
	eat count.
	- It sets the philosopher's shared data pointer to the `data` argument.
*/
static void	ft_set_table(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->nbr_of_philos)
		pthread_mutex_init(&data->mutex_forks[i], NULL);
	pthread_mutex_init(&data->mutex_exit, NULL);
	pthread_mutex_init(&data->mutex_printf, NULL);
	i = -1;
	while (++i < data->nbr_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].mutex_fork_left = &data->mutex_forks[i];
		data->philos[i].mutex_fork_right
			= &data->mutex_forks[(i + 1) % data->nbr_of_philos];
		pthread_mutex_init(&data->philos[i].mutex_last_meal, NULL);
		pthread_mutex_init(&data->philos[i].mutex_eat_count, NULL);
		data->philos[i].data = data;
	}
}

/*
1.	It waits for the death monitoring thread to finish using
	`pthread_join(data->monitor_death, NULL)`.
2.	If the number of meals to eat is greater than 0 and there is more than
	one philosopher, it waits for the meals monitoring thread to finish using
	`pthread_join(data->monitor_meals, NULL)`.
3.	It waits for each philosopher's thread to finish. For each philosopher,
	it calls `pthread_join(data->thread[i], NULL)`.
4.	It destroys the mutex for each fork and for each philosopher's last meal
	time and eat count. For each philosopher, it calls
	`pthread_mutex_destroy(&data->mutex_forks[i])`,
	`pthread_mutex_destroy(&data->philos[i].mutex_last_meal)`, and
	`pthread_mutex_destroy(&data->philos[i].mutex_eat_count)`.
5.	It destroys the mutex for the exit condition
	(`pthread_mutex_destroy(&data->mutex_exit)`) and for the print operation
	(`pthread_mutex_destroy(&data->mutex_printf)`).
6.	It frees the memory allocated for the philosophers (`free(data->philos)`),
	their threads (`free(data->thread)`), and their forks
	(`free(data->mutex_forks)`).
*/
static void	ft_clear_table(t_data *data)
{
	int		i;

	i = -1;
	pthread_join(data->monitor_death, NULL);
	if (data->meals_to_eat > 0 && data->nbr_of_philos > 1)
		pthread_join(data->monitor_meals, NULL);
	while (++i < data->nbr_of_philos)
		pthread_join(data->thread[i], NULL);
	i = -1;
	while (++i < data->nbr_of_philos)
	{
		pthread_mutex_destroy(&data->mutex_forks[i]);
		pthread_mutex_destroy(&data->philos[i].mutex_last_meal);
		pthread_mutex_destroy(&data->philos[i].mutex_eat_count);
	}
	pthread_mutex_destroy(&data->mutex_exit);
	pthread_mutex_destroy(&data->mutex_printf);
	free(data->philos);
	free(data->thread);
	free(data->mutex_forks);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_get_input(&data, ac, av) == RET_FALIURE)
		return (EXIT_FAILURE);
	if (data.meals_to_eat == 0)
		return (EXIT_SUCCESS);
	if (ft_init_data(&data) == RET_FALIURE)
		return (EXIT_FAILURE);
	ft_set_table(&data);
	if (ft_simulation(&data) == RET_FALIURE)
		return (ft_error(ERR_THREAD), ft_clear_table(&data), EXIT_FAILURE);
	ft_clear_table(&data);
	return (EXIT_SUCCESS);
}
