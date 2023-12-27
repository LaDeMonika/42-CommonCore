/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:00:10 by msimic            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:19 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack_node **lst)
{
	int				count;
	t_stack_node	*current_list;

	count = 0;
	if (lst)
		current_list = *lst;
	else
		current_list = NULL;
	while (current_list)
	{
		current_list = current_list->next;
		count++;
	}
	return (count);
}

t_stack_node	*ft_lstnew(long int content)
{
	t_stack_node	*lst;

	lst = malloc(sizeof(t_stack_node));
	if (!lst)
		return (NULL);
	lst->nbr = content;
	lst->index = 0;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *knew)
{
	t_stack_node	*last_lst;

	if (lst)
	{
		last_lst = ft_lstlast(*lst);
		if (knew)
		{
			if (last_lst)
				last_lst->next = knew;
			else
				*lst = knew;
		}
	}
}

int	sort_check(t_stack_node **stack)
{
	t_stack_node	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->nbr > temp->next->nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}
