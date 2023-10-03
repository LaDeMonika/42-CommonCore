/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:42 by msimic            #+#    #+#             */
/*   Updated: 2023/09/09 17:48:30 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*s_byte;
	const unsigned char	*last_c;

	s_byte = (const unsigned char *)s;
	last_c = NULL;
	if ((unsigned char)c == '\0')
	{
		while (*s_byte != '\0')
			s_byte++;
		return ((char *)s_byte);
	}
	while (*s_byte != '\0')
	{
		if (*s_byte == (unsigned char)c)
			last_c = s_byte;
		s_byte++;
	}
	if (last_c == NULL)
		return (NULL);
	return ((char *)last_c);
}
