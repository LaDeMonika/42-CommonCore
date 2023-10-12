/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:31:52 by msimic            #+#    #+#             */
/*   Updated: 2023/10/12 16:18:36 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*s_byte;

	if (!s)
		return (NULL);
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

void	funcfjoin(char *s1, char *s2, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	funcfjoin(s1, s2, str);
	free(s1);
	return (str);
}
