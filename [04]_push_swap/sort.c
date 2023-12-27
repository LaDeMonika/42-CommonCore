/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:07:17 by msimic            #+#    #+#             */
/*   Updated: 2023/12/26 14:47:33 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!sort_check(stack_a))
		swap_write(stack_a, stack_b, 'a');
}

void	sort_three(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	temp = *stack_a;
	if (sort_check(stack_a))
		return ;
	if (temp->nbr < temp->next->nbr)
	{
		reverse_rotate_write(stack_a, stack_b, 'a');
		if (!sort_check(stack_a))
			swap_write(stack_a, stack_b, 'a');
	}
	else if (temp->nbr > temp->next->next->nbr)
	{
		rotete_write(stack_a, stack_b, 'a');
		if (!sort_check(stack_a))
			swap_write(stack_a, stack_b, 'a');
	}
	else
		swap_write(stack_a, stack_b, 'a');
}

void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b, int x)
{
	t_stack_node	*temp;

	temp = *stack_a;
	if (sort_check(stack_a))
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->index == x)
		reverse_rotate_write(stack_a, stack_b, 'a');
	while ((*stack_a)->index != x)
		rotete_write(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'b');
	sort_three(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	temp = *stack_a;
	if (sort_check(stack_a))
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	if (temp->index == 1 || temp->next->index == 1)
	{
		while ((*stack_a)->index != 1)
			reverse_rotate_write(stack_a, stack_b, 'a');
	}
	else
	{
		while ((*stack_a)->index != 1)
			rotete_write(stack_a, stack_b, 'a');
	}
	push(stack_a, stack_b, 'b');
	sort_four(stack_a, stack_b, 2);
	push(stack_b, stack_a, 'a');
}

void	ft_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	count;

	count = ft_lstsize(stack_a);
	if (count <= 1)
		return ;
	else if (count == 2)
		sort_two(stack_a, stack_b);
	else if (count == 3)
		sort_three(stack_a, stack_b);
	else if (count == 4)
		sort_four(stack_a, stack_b, 1);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
