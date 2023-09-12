/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:10:52 by msimic            #+#    #+#             */
/*   Updated: 2023/09/07 15:10:53 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>

int main()
{
    char str1[] = "6";
    char str2[] = "#";
    int rez1 = ft_isalnum(str1);
    int rez2 = ft_isalnum(str2);

    printf("ovo su br: %d\n", rez1);
    printf("ovo su char: %d", rez2);
}
*/
