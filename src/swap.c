/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:04:30 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 20:52:01 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_node **stack)
{
    if (*stack && (*stack)->next)
    {
        t_node *first = *stack;
        t_node *second = (*stack)->next;
        first->next = second->next;
        second->next = first;
        *stack = second;
    }
}

/* int	sa(t_list **stack_a)
{
	if (swap(stack_a))
}

int	sb(t_list **stack_b)
{
	
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	
} */