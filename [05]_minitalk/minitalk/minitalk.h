/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:25:42 by msimic            #+#    #+#             */
/*   Updated: 2023/12/29 21:52:35 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

//****************client.c*************
void	validation(int ac, char **av);
void	send_bit(int srv_pid, char c);

//****************server.c*************
void	which_signal(int sig, siginfo_t *siginfo, void *context);

//****************UTILS****************
void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *));
void	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	put_nbr(int n);
int		ft_atoi(char *str);

#endif