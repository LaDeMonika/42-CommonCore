/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:16 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 11:39:38 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
1.	It locks the mutex_last_meal mutex to prevent other threads from accessing
	the last_eat field.
2.	It reads the value of the last_eat field and stores it in the ret variable.
3.	It unlocks the mutex_last_meal mutex to allow other threads to access the
	last_eat field.
4.	It returns the value that was read from the last_eat field.
*/
static u_int64_t	get_time_last_meal(t_philo *philo)
{
	u_int64_t	ret;

	pthread_mutex_lock(&philo->mutex_last_meal);
	ret = philo->last_eat;
	pthread_mutex_unlock(&philo->mutex_last_meal);
	return (ret);
}

/*
1.	It casts the arg argument to a t_data pointer and stores it in data.
2.	It enters a loop that continues as long as the simulation is not marked as
	exited (ft_is_exit(data) returns false).
3.	Inside the loop, it iterates over all philosophers in the simulation.
4.	For each philosopher, it checks if the time since their last meal
	(ft_get_time(get_time_last_meal(&data->philos[i]))) is greater than the time
	they are allowed to go without eating (data->time_to_die).
5.	If a philosopher has gone too long without eating, it prints their state as
	"died" (ft_print_state(&data->philos[i], "died")), marks the simulation as
	exited (ft_set_exit(data)), and returns from the function.
6.	If no philosopher has died, it pauses for 1 millisecond (usleep(1000))
	before checking again.
7.	If the simulation is marked as exited, it returns from the function.
*/
static void	*ft_monitor_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!ft_is_exit(data))
	{
		i = 0;
		while (i < data->nbr_of_philos)
		{
			if (ft_get_time(get_time_last_meal(&data->philos[i]))
				> (u_int64_t)data->time_to_die)
				return (ft_print_state(&data->philos[i], "died"),
					ft_set_exit(data), NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

/*
1.	It casts the arg argument to a t_data pointer and stores it in data.
2.	It enters a loop that continues as long as the simulation is not marked
	as exited (ft_is_exit(data) returns false).
3.	Inside the loop, it iterates over all philosophers in the simulation.
4.	For each philosopher, it checks if the number of meals they have eaten
	(ft_get_eat_count(&data->philos[i])) is less than the required number of
	meals (data->meals_to_eat).
5.	If all philosophers have eaten the required number of meals, it marks the
	simulation as exited (ft_set_exit(data)) and returns from the function.
6.	If not all philosophers have eaten the required number of meals, it pauses
	for 1 millisecond (usleep(1000)) before checking again.
7.	If the simulation is marked as exited, it returns from the function.
*/
static void	*ft_monitor_eat_count(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!ft_is_exit(data))
	{
		i = -1;
		while (++i < data->nbr_of_philos)
			if (ft_get_eat_count(&data->philos[i]) < data->meals_to_eat)
				break ;
		if (i == data->nbr_of_philos)
			return (ft_set_exit(data), NULL);
		usleep(1000);
	}
	return (NULL);
}

/*
1.	It initializes the start_time field of data to the current time.
2.	It sets the last_eat field of each philosopher to the start time of the
	simulation. This represents that all philosophers start eating at the
	beginning of the simulation.
3.	It creates a new thread for each philosopher. The ft_routine function is
	used as the start routine for these threads, and the address of each
	philosopher is passed as the argument to the start routine.
4.	If any thread creation fails, it returns RET_FAILURE.
5.	It creates a new thread to monitor the philosophers for death.
	The ft_monitor_death function is used as the start routine for this thread,
	and the address of data is passed as the argument to the start routine.
6.	If the number of meals to eat is greater than 0 and the number of
	philosophers is more than 1, it creates a new thread to monitor the
	philosophers for whether they have eaten the required number of meals.
	The ft_monitor_eat_count function is used as the start routine for this
	thread, and the address of data is passed as the argument to the start
	routine.
7.	If any thread creation fails, it returns RET_FAILURE.
8.	If all thread creations succeed, it returns RET_SUCCESS.
*/
bool	ft_simulation(t_data *data)
{
	int		i;

	i = -1;
	data->start_time = ft_get_time(0);
	while (++i < data->nbr_of_philos)
		data->philos[i].last_eat = data->start_time;
	i = -1;
	while (++i < data->nbr_of_philos)
		if (pthread_create(&data->thread[i], NULL,
				&ft_routine, (void *)&data->philos[i]))
			return (RET_FALIURE);
	if (pthread_create(&data->monitor_death, NULL, &ft_monitor_death,
			(void *)data) || (data->meals_to_eat > 0 && data->nbr_of_philos
			> 1 && pthread_create(&data->monitor_meals, NULL,
				&ft_monitor_eat_count, (void *)data)))
		return (RET_FALIURE);
	return (RET_SUCCESS);
}
