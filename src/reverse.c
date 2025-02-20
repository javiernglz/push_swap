/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:33:55 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 20:51:57 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void reverse_rotate(t_node **stack)
{
    if (*stack && (*stack)->next)
    {
        t_node *prev = NULL;
        t_node *last = *stack;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        if (prev)
        {
            prev->next = NULL;
            last->next = *stack;
            *stack = last;
        }
    }
}