/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:33:52 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 20:52:11 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_node **src, t_node **dst)
{
    if (*src)
    {
        t_node *temp = *src;
        *src = (*src)->next;
        temp->next = *dst;
        *dst = temp;
    }
}