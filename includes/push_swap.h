/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:39:06 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/21 00:34:52 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

//Algorithm
void	small_sort(t_list **t_list_a, t_list **t_list_b);
int		stack_size(t_list *stack);

//Radix functions
int		is_sorted(t_list **stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	sort_stack_b(t_list **stack_a, t_list **stack_b, int bit_size, int j);


//Stack Utils functions
void 	free_stack(t_list **stack);
void	index_stack(t_list **stack);
int		find_index_position(t_list *stack, int value);

//Utils functions
void	print_stack(t_list *stack);
void	ft_free(char **str);
long	ft_atol(const char *str);

//Push Swap movements functions
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

//Error arguments
int		is_valid_number(char *num);
int		has_duplicates(char **args, int index, long num);
void	arguments(int argc, char **argv);

#endif