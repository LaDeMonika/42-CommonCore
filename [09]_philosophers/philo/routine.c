/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:14 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 11:40:41 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
1.	It locks the philosopher's left fork.
2.	It prints the state of the philosopher as "has taken a fork".
3.	It enters a loop that continues as long as the simulation is not marked as
	exited (ft_is_exit(philo->data) returns false). Inside the loop, it pauses
	for 10 microseconds (usleep(10)) at a time. This is done to prevent the loop
	from using too much CPU time.
4.	Once the simulation is marked as exited, it unlocks the philosopher's left
	fork using pthread_mutex_unlock(philo->mutex_fork_left).
*/
static void	*ft_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_fork_left);
	ft_print_state(philo, "has taken a fork");
	while (!ft_is_exit(philo->data))
		usleep(10);
	pthread_mutex_unlock(philo->mutex_fork_left);
	return (NULL);
}

/*
1.	It checks if the philosopher's ID is even.
2.	If the ID is even, it locks the philosopher's left fork and then locks the
	right fork. After locking each fork, it prints the state of the philosopher
	as "has taken a fork".
3.	If the ID is odd, it locks the philosopher's right fork and then locks the
	left fork. After locking each fork, it prints the state of the philosopher as
	"has taken a fork".
*/
static void	ft_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->mutex_fork_left);
		ft_print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->mutex_fork_right);
		ft_print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->mutex_fork_right);
		ft_print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->mutex_fork_left);
		ft_print_state(philo, "has taken a fork");
	}
}

/*
1.	It checks if the philosopher's ID is even.
2.	If the ID is even, it unlocks the philosopher's left fork and then unlocks
	the right fork.
3.	If the ID is odd, it unlocks the philosopher's right fork and then unlocks
	the left fork.
*/
static void	ft_put_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->mutex_fork_left);
		pthread_mutex_unlock(philo->mutex_fork_right);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex_fork_right);
		pthread_mutex_unlock(philo->mutex_fork_left);
	}
}

/*
1.	It checks if there is only one philosopher. If so, it calls the ft_one_philo
	function and returns.
2.	If the philosopher's ID is odd, it pauses for 50 microseconds to stagger the
	start times of the philosophers.
3.	It enters a loop that continues as long as the simulation is not marked as
	exited and the philosopher has not eaten the required number of meals.
4.	Inside the loop, it simulates the philosopher's actions in the following
	order:
	-	The philosopher takes two forks using ft_take_forks.
	-	The philosopher's state is printed as "is eating".
	- 	The time of the philosopher's last meal is updated. If the simulation is
		marked as exited at this point, the philosopher puts down the forks and
		the function returns.
	- 	The philosopher waits for the time it takes to eat using ft_wait.
	- 	The philosopher puts down the forks using ft_put_forks.
	- 	The philosopher's state is printed as "is sleeping".
	- 	The count of meals the philosopher has eaten is incremented. If the
		simulation is marked as exited at this point, the function returns.
	- 	The philosopher waits for the time it takes to sleep using ft_wait.
	- 	The philosopher's state is printed as "is thinking".
	- 	If the number of philosophers is odd and the simulation is not marked as
		exited, the philosopher waits for a certain amount of time before the
		next cycle.
5.	Once the loop ends, the function returns.
*/
void	*ft_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->data->nbr_of_philos == 1)
		return (ft_one_philo(philo));
	if (philo->id % 2)
		usleep(50);
	while (!ft_is_exit(philo->data) && (philo->data->meals_to_eat < 0
			|| ft_get_eat_count(philo) < philo->data->meals_to_eat))
	{
		ft_take_forks(philo);
		ft_print_state(philo, "is eating");
		if (ft_set_time_last_meal(philo) && ft_is_exit(philo->data))
			return (ft_take_forks(philo), NULL);
		ft_wait(philo->data->time_to_eat);
		ft_put_forks(philo);
		ft_print_state(philo, "is sleeping");
		if (ft_increment_eat_count(philo) && ft_is_exit(philo->data))
			return (NULL);
		ft_wait(philo->data->time_to_sleep);
		ft_print_state(philo, "is thinking");
		if ((philo->data->nbr_of_philos % 2) && !ft_is_exit(philo->data))
			ft_wait(philo->data->time_to_eat * 2 - philo->data->time_to_sleep);
	}
	return (NULL);
}
