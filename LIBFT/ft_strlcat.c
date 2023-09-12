/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:25:39 by msimic            #+#    #+#             */
/*   Updated: 2023/09/11 19:13:05 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	b = 0;
	while (dest[b] != '\0' && b < size)
	{
		b++;
	}
	a = b;
	while (src[b - a] && b + 1 < size)
	{
		dest[b] = src[b - a];
		b++;
	}
	if (a < size)
		dest[b] = '\0';
	return (a + ft_strlen(src));
}
