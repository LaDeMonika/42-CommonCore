/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:22:07 by msimic            #+#    #+#             */
/*   Updated: 2023/12/26 14:22:19 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	long				nbr;
	long				index;
	struct s_stack_node	*next;
}						t_stack_node;

//***OPERATIONS***
void					ft_swap(t_stack_node **stack);
void					swap_write(t_stack_node **stack_a,
							t_stack_node **stack_b, char operaion_type);
void					ft_rotate(t_stack_node **stack);
void					rotete_write(t_stack_node **stack_a,
							t_stack_node **stack_b, char operation_type);
void					ft_reverse_rotate(t_stack_node **stack);
void					reverse_rotate_write(t_stack_node **stack_a,
							t_stack_node **stack_b, char o_type);
void					push(t_stack_node **src, t_stack_node **dest,
							char o_type);

//***UTILS***
t_stack_node			*ft_lstlast(t_stack_node *lst);
int						ft_lstsize(t_stack_node **lst);
t_stack_node			*ft_lstnew(long int content);
void					ft_lstadd_back(t_stack_node **lst, t_stack_node *knew);
int						sort_check(t_stack_node **stack);
size_t					ft_strlen(const char *str);
void					ft_error(void);
long int				ft_atoi(const char *str);
char					*ft_strdup(char *src);
char					*ft_strjoin(char *s1, char const *s2);
char					*ft_strncpy(char *s1, char *s2, int n);
int						count_words(char *str);
char					**ft_split(char *str);
int						if_empti_of_space(const char *str);
int						check(char *str);
void					assign(t_stack_node **stack);

//***SORT***
void					sort_two(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_three(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_four(t_stack_node **stack_a,
							t_stack_node **stack_b, int x);
void					sort_five(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					ft_sort(t_stack_node **stack_a, t_stack_node **stack_b);

//***ALGORITHM***
int						sorted(t_stack_node **stack);
void					radix(t_stack_node **stack_a, t_stack_node **stack_b);

//***PUSH_SWAP***
void					free_str(char **str);
void					free_stack(t_stack_node **stack_a);
int						error_write(t_stack_node **stack_a);
void					while_loop(char **s, t_stack_node **stack, int *i);
void					change(char *str, t_stack_node **stack);
int						main(int ac, char **av);

#endif