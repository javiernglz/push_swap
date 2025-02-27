/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:33:58 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 20:51:59 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rotate(t_node **stack)
{
    if (*stack && (*stack)->next)
    {
        t_node *first = *stack;
        t_node *last = *stack;
        while (last->next)
            last = last->next;
        *stack = first->next;
        first->next = NULL;
        last->next = first;
    }
}