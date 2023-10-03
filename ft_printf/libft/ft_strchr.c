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

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*s_byte;

	s_byte = (const unsigned char *)s;
	if ((unsigned char)c == '\0')
	{
		while (*s_byte != '\0')
			s_byte++;
		return ((char *)s_byte);
	}
	while (*s_byte != '\0')
	{
		if (*s_byte == (unsigned char)c)
			return ((char *)s_byte);
		s_byte++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
    char *string = "YIIHIIIjk";
    char *findchr = ft_strchr(string, 'I');
    
    printf("Tadam: %s\n", findchr);
    
}
//worksss
*/
