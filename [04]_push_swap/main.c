/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:28:10 by msimic            #+#    #+#             */
/*   Updated: 2023/12/26 14:28:37 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			*str;
	int				i;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 2;
	str = ft_strdup(av[1]);
	if (check(str))
		return (0);
	change(str, &stack_a);
	assign(&stack_a);
	ft_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
