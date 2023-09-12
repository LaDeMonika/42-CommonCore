/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:18 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 19:22:01 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t len)
{
    unsigned char    *d;
    unsigned char    *s;
    
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (!dest && !src)
        return (dest);
    while (len--)
    {
        *d++ = *s++;
    }
    return (dest);
}
int main ()
{
    //idk
}