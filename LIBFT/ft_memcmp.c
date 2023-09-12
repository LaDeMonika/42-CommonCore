/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:15 by msimic            #+#    #+#             */
/*   Updated: 2023/09/09 21:42:03 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *d1;
    unsigned char *d2;
    
    d1 = (unsigned char *)s1;
    d2 = (unsigned char *)s2;
    if (!n)
        return (0);
    while (--n && *d1 == *d2)
    {
        d1++;
        d2++;
    }
    return ((int)(*d1 - *d2));
}
int main()
{
    //nez
}