/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:26:32 by msimic            #+#    #+#             */
/*   Updated: 2023/12/25 18:12:24 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack_node **stack)
{
	t_stack_node	*cur;

	cur = *stack;
	while (cur->next != NULL)
	{
		if (cur->nbr > cur->next->nbr)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	radix(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	temp;
	int	digit;

	temp = 0;
	digit = 1;
	while (!sorted(stack_a))
	{
		while (!((*stack_a)->index == temp))
		{
			if (((*stack_a)->index & digit) == 0)
				push(stack_a, stack_b, 'b');
			else
			{
				if (temp == 0)
					temp = (*stack_a)->index;
				rotete_write(stack_a, stack_b, 'a');
			}
		}
		temp = 0;
		while (*stack_b != NULL)
			push(stack_b, stack_a, 'a');
		digit = digit * 2;
	}
}
