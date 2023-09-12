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

char	*ft_tolower(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr >= 'A' && *ptr <= 'Z')
		{
			*ptr = *ptr + 32;
		}
		ptr++;
	}
	return (str);
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
