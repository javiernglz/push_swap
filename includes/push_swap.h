/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:39:06 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/16 18:02:15 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;


int		get_distance(t_list *stack, int value);
void	print_stack(t_list *stack);
void	make_top(t_list **stack, int distance);
void	ft_check_args(int argc, char **argv);
void	ft_error(char *msg);

void 	free_stack(t_list **stack);

/* void	push(t_list **src, t_list **dst);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b); */

int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverseRotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

void	radix_sort(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack);

void	small_sort(t_list **t_list_a, t_list **t_list_b);
int		stack_size(t_list *stack);

void	index_stack(t_list **stack);
void	ft_free(char **str);

void print_stack_index(t_list *stack);

#endif