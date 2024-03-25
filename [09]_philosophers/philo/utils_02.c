/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:34:14 by msimic            #+#    #+#             */
/*   Updated: 2024/03/14 11:39:53 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_puterror(const char *fault, const char *msg)
{
	if (fault && ft_strlen(fault))
		printf("\nERROR: %s\n", fault);
	if (msg && ft_strlen(msg))
		printf("\nExpected: %s\n", msg);
	printf("\n");
}

void	ft_error(char err)
{
	if (err == ERR_MALLOC)
		ft_puterror("Malloc failed", "Memory allocation failed");
	else if (err == ERR_TOO_FEW_ARGS)
		ft_puterror("Too few arguments",
			"[nm.of.ph][tm.to.d][tm.to.et][tm.to.slp][nm.tm.ph.mst.et]");
	else if (err == ERR_TOO_MANY_ARGS)
		ft_puterror("Too many arguments",
			"[nm.of.ph][tm.to.d][tm.to.et][tm.to.slp][nm.tm.ph.mst.et]");
	else if (err == ERR_THREAD)
		ft_puterror("Thread creation failed", "Thread creation");
	else if (err == ERR_PHILO)
		ft_puterror("", "Number of philosophers must be positive integer");
	else if (err == ERR_ARG_EAT_LIMIT)
		ft_puterror("", "Number of meals must be positive integer");
	else if (err == ERR_ARG_TIME_TO_SLEEP)
		ft_puterror("", "Time to sleep must be positive integer");
	else if (err == ERR_ARG_TIME_TO_EAT)
		ft_puterror("", "Time to eat must be positive integer");
	else if (err == ERR_ARG_TIME_TO_DIE)
		ft_puterror("", "Time to die must be positive integer");
}
