/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:28 by msimic            #+#    #+#             */
/*   Updated: 2023/09/09 17:41:46 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strchr(const char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
        {
            return ((char *) str);
        }
        str++;
    }
    return (0);
}

#include <stdio.h>

int main()
{
    char *string = "YIIHIIIjk";
    char *findchr = ft_strchr(string, 'I');
    
    printf("Tadam: %s\n", findchr);
    
}
//worksss