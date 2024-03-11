/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:21:10 by msimic            #+#    #+#             */
/*   Updated: 2024/01/03 21:21:10 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int argument, size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *) str;
	while (i < size)
	{
		if (*(s + i) == (unsigned char) argument)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
