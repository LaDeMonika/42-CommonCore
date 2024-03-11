/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:47 by msimic            #+#    #+#             */
/*   Updated: 2023/09/07 15:11:48 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
/*
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char    str[] = "DHGjgjhFHGHafdf";

    ft_tolower(str);
    printf("lower: %s", str);
}
*/
