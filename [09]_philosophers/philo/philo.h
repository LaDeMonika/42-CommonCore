/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:41:35 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 10:34:35 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************* INCLUDES */
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>

/******************************* STRUCT */
struct	s_philo;
struct	s_data;

typedef struct s_philo
{
	int					id;
	int					eat_count;
	u_int64_t			last_eat;
	pthread_mutex_t		*mutex_fork_left;
	pthread_mutex_t		*mutex_fork_right;
	pthread_mutex_t		mutex_eat_count;
	pthread_mutex_t		mutex_last_meal;
	struct s_data		*data;
}				t_philo;

typedef struct s_data
{
	int					nbr_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_to_eat;
	bool				exit;
	u_int64_t			start_time;
	struct s_philo		*philos;
	pthread_mutex_t		mutex_exit;
	pthread_mutex_t		mutex_printf;
	pthread_mutex_t		*mutex_forks;
	pthread_t			*thread;
	pthread_t			monitor_death;
	pthread_t			monitor_meals;
}					t_data;

/******************************* ENUMS */
enum e_return
{
	RET_SUCCESS,
	RET_FALIURE
};

enum e_errors
{
	ERR_TOO_FEW_ARGS,
	ERR_TOO_MANY_ARGS,
	ERR_MALLOC,
	ERR_THREAD,
	ERR_PHILO,
	ERR_ARG_TIME_TO_SLEEP,
	ERR_ARG_TIME_TO_EAT,
	ERR_ARG_TIME_TO_DIE,
	ERR_ARG_EAT_LIMIT,
};

enum e_philo_vars
{
	TIME_LAST_EAT,
	INCREMENT_EAT_COUNT,
};

/******************************* FUNCTIONS */
//simulation.c
bool			ft_simulation(t_data *data);
//routine.c -> routine functions for the philos and the monitor threads
void			*ft_routine(void *arg);
//utils_00.c -> print functions and time functions
void			ft_print_state(t_philo *philo, const char *state);
u_int64_t		ft_get_time(u_int64_t relative);
void			ft_wait(u_int64_t time);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
//utils_01.c -> mutex functions
bool			ft_is_exit(t_data *data);
void			ft_set_exit(t_data *data);
bool			ft_set_time_last_meal(t_philo *philo);
bool			ft_increment_eat_count(t_philo *philo);
int				ft_get_eat_count(t_philo *philo);
//init_02.c -> error handling
void			ft_error(char err);

#endif
