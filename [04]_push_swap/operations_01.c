/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:38:36 by msimic            #+#    #+#             */
/*   Updated: 2023/12/26 14:40:02 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest, char o_type)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;

	temp_a = *src;
	temp_b = *dest;
	if (temp_a == NULL)
		return ;
	*src = temp_a->next;
	temp_a->next = temp_b;
	*dest = temp_a;
	if (o_type == 'a')
		write(1, "pa\n", 3);
	else if (o_type == 'b')
		write(1, "pb\n", 3);
}

void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	int				i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}

void	reverse_rotate_write(t_stack_node **stack_a, t_stack_node **stack_b,
		char o_type)
{
	if (o_type == 'a' && ft_lstsize(stack_a) >= 2)
	{
		ft_reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	else if (o_type == 'b' && ft_lstsize(stack_b) >= 2)
	{
		ft_reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (o_type == 'r' && ft_lstsize(stack_b) >= 2
		&& ft_lstsize(stack_a) >= 2)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
