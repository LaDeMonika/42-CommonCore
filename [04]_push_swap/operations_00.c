/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:16 by msimic            #+#    #+#             */
/*   Updated: 2023/12/25 18:12:42 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	swap_write(t_stack_node **stack_a, t_stack_node **stack_b,
		char operaion_type)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (operaion_type == 'a' && temp_a && temp_a->next)
	{
		ft_swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (operaion_type == 'b' && temp_b && temp_b->next)
	{
		ft_swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (!temp_a || !temp_b || !temp_a->next || !temp_b->next)
		return ;
	else
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		write(1, "ss\n", 3);
	}
}

void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	rotete_write(t_stack_node **stack_a, t_stack_node **stack_b,
		char operation_type)
{
	if (operation_type == 'a' && ft_lstsize(stack_a) >= 2)
	{
		ft_rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if (operation_type == 'b' && ft_lstsize(stack_b) >= 2)
	{
		ft_rotate(stack_b);
		write(1, "rb\n", 3);
	}
	else if (operation_type == 'r' && ft_lstsize(stack_a) >= 2
		&& ft_lstsize(stack_b) >= 2)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
