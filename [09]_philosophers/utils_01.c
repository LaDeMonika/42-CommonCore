/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:21 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 11:40:04 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
1. 	It locks the `mutex_exit` mutex to prevent other threads from accessing
	the `exit` field.
2. 	It reads the value of the `exit` field and stores it in the `ret` variable.
3. 	It unlocks the `mutex_exit` mutex to allow other threads to access the
	`exit` field.
4. 	It returns the value that was read from the `exit` field.
*/
bool	ft_is_exit(t_data *data)
{
	bool	ret;

	pthread_mutex_lock(&data->mutex_exit);
	ret = data->exit;
	pthread_mutex_unlock(&data->mutex_exit);
	return (ret);
}

/*
1. 	It locks the `mutex_exit` mutex to prevent other threads from accessing
	the `exit` field.
2. 	It sets the value of the `exit` field to `true`.
3. 	It unlocks the `mutex_exit` mutex to allow other threads to access the
	`exit` field.
*/
void	ft_set_exit(t_data *data)
{
	pthread_mutex_lock(&data->mutex_exit);
	data->exit = true;
	pthread_mutex_unlock(&data->mutex_exit);
}

/*
1. 	It locks the `mutex_last_meal` mutex to prevent other threads from
	accessing the `last_eat` field.
2. 	It sets the value of the `last_eat` field to the current time.
3. 	It unlocks the `mutex_last_meal` mutex to allow other threads to
	access the `last_eat` field.
4. 	It returns `true` to indicate that the operation was successful.
*/
bool	ft_set_time_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_last_meal);
	philo->last_eat = ft_get_time(0);
	pthread_mutex_unlock(&philo->mutex_last_meal);
	return (RET_SUCCESS);
}

/*
1. 	It locks the `mutex_eat_count` mutex to prevent other threads
	from accessing the `eat_count` field.
2. 	It increments the value of the `eat_count` field by 1.
3. 	It unlocks the `mutex_eat_count` mutex to allow other threads to
	access the `eat_count` field.
4. 	It returns `true` to indicate that the operation was successful.
*/
bool	ft_increment_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_eat_count);
	return (RET_SUCCESS);
}

/*
1. 	It locks the `mutex_eat_count` mutex to prevent other threads from
	accessing the `eat_count` field.
2. 	It reads the value of the `eat_count` field and stores it in the `ret`
	variable.
3. 	It unlocks the `mutex_eat_count` mutex to allow other threads to access the
	`eat_count` field.
4. 	It returns the value that was read from the `eat_count` field.
*/
int	ft_get_eat_count(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->mutex_eat_count);
	ret = philo->eat_count;
	pthread_mutex_unlock(&philo->mutex_eat_count);
	return (ret);
}
