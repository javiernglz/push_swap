/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:39:06 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 21:41:30 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *a;
    t_node *b;
} t_stack;

t_node *new_node(int value);

void push(t_node **src, t_node **dst);
void swap(t_node **stack);
void rotate(t_node **stack);
void reverse_rotate(t_node **stack);

void radix_sort(t_stack *stack, int size);
void print_stack(t_node *stack);
void normalized_indice(t_node *stack, int size);
int is_stack_sorted(t_node *stack);
void free_stack(t_node *stack);

#endif