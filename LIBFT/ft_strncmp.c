/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:11:34 by msimic            #+#    #+#             */
/*   Updated: 2023/09/07 15:11:35 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && (i < n - 1))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	unsigned int	s;

	if (argc == 1)
		return (0);
	s = 2;
	printf("Result: %d\n", ft_strncmp(argv[1], argv[2], s));
	printf("Result2: %d\n", strncmp(argv[1], argv[2], s));	
}
*/