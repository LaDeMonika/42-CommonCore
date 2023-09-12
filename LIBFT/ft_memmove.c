/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:22 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 19:23:32 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char *d;
    unsigned char *s;
    
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (!dest && !src)
    {
        return (dest);
    }
    if (src < dest)
    {
        while (len--)
        {
            d[len] = s[len];
        }
    }
    else
    {
    	while (len--)
        {
        	*d++ = *s++;
        }
    }
    return (dest); 
}
