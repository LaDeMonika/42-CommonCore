/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:39 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 16:13:40 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
haystack: Ovo je niz znakova (string) u kojem želite tražiti podniz.
needle: Ovo je podniz koji želite pronaći unutar haystack niza.
len: Ovo je broj znakova iz haystack niza koji želite pretraživati (ograničava pretragu).
*/
/*
Funkcija strnstr se koristi za pretraživanje podniza znakova unutar
drugog niza znakova, ali s ograničenjem na određeni broj znakova. 
*/
#include "libft.h"

char    *ft_strnstr(const char  *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;
    
    i = 0;
    j = 0;
    if (!*needle)
    {
        return ((char *)haystack);
    }
    while (haystack[i] != '\0' && i < len)
    {
        if (haystack[i] == needle[0])
        {
            while (needle[j] != '\0' && haystack[i + j] == needle[j] && i + j < len)
            {
                if (needle[j + 1] == '\0')
                {
                    return ((char *)&haystack[i]);
                }
                j++;
            }
        }
        i++;
    }
    return (NULL);
}
int main()
{
    //idk
}
