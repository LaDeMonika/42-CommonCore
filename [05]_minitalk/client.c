/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:17:38 by msimic            #+#    #+#             */
/*   Updated: 2023/12/30 14:19:15 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit;

void	received(int sig)
{
	if (sig == SIGUSR1)
	{
		g_bit++;
		write(1, "1", 1);
	}
	else if (sig == SIGUSR2)
	{
		g_bit++;
		write(1, "0", 1);
	}
	else
	{
		ft_putstr("Error: Signal is invalid.\n");
		exit(EXIT_FAILURE);
	}
}

void	validation(int ac, char **av)
{
	size_t	i;
	int		pid;

	if (ac != 3)
	{
		ft_putstr("Error: Wrong number of arguments.\n");
		ft_putstr("Usage: ./client <PID> <string>\n");
		exit(EXIT_FAILURE);
	}
	i = -1;
	pid = ft_atoi(av[1]);
	while (av[1][++i])
	{
		if (pid <= 0)
		{
			ft_putstr("Error: PID is invalid.\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	send_bit(int srv_pid, char c)
{
	while (g_bit < 8)
	{
		if ((128 >> g_bit) & c)
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		usleep(5000);
		if (g_bit == 8)
		{
			g_bit = 0;
			write(1, " ", 1);
			return ;
		}
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		srv_pid;

	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	validation(ac, av);
	srv_pid = ft_atoi(av[1]);
	i = -1;
	g_bit = 0;
	while (av[2][++i])
		send_bit(srv_pid, av[2][i]);
	send_bit(srv_pid, '\n');
	exit(0);
}
