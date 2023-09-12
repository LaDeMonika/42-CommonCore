/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:03 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 19:03:13 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int c1;
	int c1;
	int rez1 = ft_str_is_alpha(c1);
	int rez2 = ft_str_is_alpha(c2);
	
	printf("rezultat 1 je : %d\n", rez1);
	printf("rezultat 2 je : %d\n", rez2);
}
*/