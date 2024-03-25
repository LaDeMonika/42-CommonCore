/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:19 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 11:40:25 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
1.	It calculates the current timestamp relative to the start time of the
	simulation.
2.	It locks the mutex_printf mutex to prevent other threads from printing
	to the console.
3.	If the simulation is not marked as exited
	(ft_is_exit(philo->data) returns false), it prints the timestamp,
	the philosopher's ID, and the philosopher's state to the console.
4.	It unlocks the mutex_printf mutex to allow other threads to print
	to the console.
*/
void	ft_print_state(t_philo *philo, const char *state)
{
	u_int64_t	timestamp;

	timestamp = ft_get_time(philo->data->start_time);
	pthread_mutex_lock(&philo->data->mutex_printf);
	if (!ft_is_exit(philo->data))
		printf("%lu %d %s\n", timestamp, philo->id, state);
	pthread_mutex_unlock(&philo->data->mutex_printf);
}

/*
1.	It declares a struct timeval variable now.
2.	It calls the gettimeofday function to get the current time and stores it
	in now.
3.	It calculates the current time in milliseconds by multiplying the seconds
	part of now by 1000 and adding the microseconds part of now divided by 1000.
4.	It subtracts the relative time from the calculated current time.
5.	It returns the calculated time.
*/
u_int64_t	ft_get_time(u_int64_t relative)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * (u_int64_t)1000) + (now.tv_usec / 1000) - relative);
}

/*
1.	It gets the current time in milliseconds and stores it in the start variable.
2.	It enters a loop where it continuously checks if the elapsed time since start
	is less than the specified time.
3.	Inside the loop, it calls usleep(500) to pause the execution for 500
	microseconds (or 0.5 milliseconds) at a time. This is done to prevent the
	loop from using too much CPU time.
4.	The loop continues until the elapsed time since start is equal to or greater
	than the specified time.
*/
void	ft_wait(u_int64_t time)
{
	u_int64_t	start;

	start = ft_get_time(0);
	while (ft_get_time(start) < time)
		usleep(500);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + str[i] - 48;
		i++;
		if (res > INT_MAX || res < 1)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
