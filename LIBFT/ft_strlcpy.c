/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:10:41 by msimic            #+#    #+#             */
/*   Updated: 2023/09/07 15:10:42 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t   ft_strlcpy(char *dest, const char *src, size_t destsize)
{
    size_t i;

    i = 0;
    if (!src || !dest)
        return (0);
    if (destsize == 0)
        return (ft_strlen(src));
    while (src[i] != '\0' && i < destsize - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}
/*
#include <stdio.h>

int main(void)
{
    provjeri kod za main
}
*/
