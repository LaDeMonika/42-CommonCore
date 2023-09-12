/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:15:43 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 16:15:44 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_toupper(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
    return (str);
}
/*
#include <stdio.h>

int main()
{
    char str[] = "khflkasjl";

    ft_toupper(str);
    printf("%s", str)
}
*/