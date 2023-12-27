/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:03:50 by msimic            #+#    #+#             */
/*   Updated: 2023/12/26 14:52:13 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_stack(t_stack_node **stack_a)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;

	temp_a = *stack_a;
	while (temp_a != NULL)
	{
		temp_b = temp_a->next;
		free(temp_a);
		temp_a = temp_b;
	}
	*stack_a = NULL;
}

int	error_write(t_stack_node **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	return (-1);
}

void	while_loop(char **s, t_stack_node **stack, int *i)
{
	long int	nbr;

	while (s[*i])
	{
		nbr = ft_atoi(s[*i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			free_str(s);
			free_stack(stack);
			exit(error_write(stack));
		}
		else
		{
			ft_lstadd_back(stack, ft_lstnew(nbr));
		}
		(*i)++;
	}
}

void	change(char *str, t_stack_node **stack)
{
	int			i;
	char		**s;

	s = ft_split(str);
	if (!s)
	{
		free_stack(stack);
		exit(error_write(stack));
	}
	if (s[0] == NULL)
	{
		free_str(s);
		free_stack(stack);
		exit(error_write(stack));
	}
	i = 0;
	while_loop(s, stack, &i);
	free_str(s);
}
