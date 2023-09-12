/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:10:44 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 19:12:36 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace(int c)
{
    return (c == '\f' || c == '\n' || c == '\r'
    || c == '\t' || c == '\v' || c == ' ');
}

int ft_atoi(const char *str)
{
    int sign;
    int number;

    sign = 1;
    number = 0;
    while(ft_isspace(*str))
    {
        str++;
    }
    if (*str == '-')
    {
        sign = -1;
    }
    if (*str == '+' || *str == '-')
    {
        str++;
    }
    while (*str >= 48 && *str <= 57)
    {
        number *= 10;
        number += *str - 48;
        ++str;
    }
    return (number * sign);
}
/*
#include <stdio.h>

int main()
{
    const char    *s1 = "-98070", *s2 = "790908";
    int a = ft_atoi(s1);
    int b = ft_atoi(s2);

    printf("ovo je atoi a: %d, a ovo b: %d\n", a, b);
    printf("ovo je string a: %s, a ovo b: %s", s1, s2);
    return 0;
}
*/