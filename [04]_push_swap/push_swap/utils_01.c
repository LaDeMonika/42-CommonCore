/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:59:20 by msimic            #+#    #+#             */
/*   Updated: 2023/12/25 18:17:11 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (2147483649);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i])
		return (2147483649);
	return (res * sign);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[len])
		len++;
	cpy = malloc(sizeof(char) * len + 1);
	if (cpy == NULL)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
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
	free(s1);
	return (str);
}

void	assign(t_stack_node **stack)
{
	t_stack_node	*lst;
	t_stack_node	*index;
	int				i;

	i = 1;
	while (i <= ft_lstsize(stack))
	{
		index = *stack;
		lst = *stack;
		while (index != NULL)
		{
			while (lst->index != 0)
				lst = lst->next;
			if (index->nbr < lst->nbr && index->index == 0)
				lst = index;
			else if (index->nbr == lst->nbr && index != lst)
				return ;
			index = index->next;
		}
		lst->index = i;
		i++;
	}
}
