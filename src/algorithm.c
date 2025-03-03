/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:01:28 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/03 22:13:57 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(t_node *t_node, int val)
{
    int	min;
	
	min = t_node->index;
    while (t_node)
    {
        if (t_node->index < min && t_node->index != val)
            min = t_node->index;
        t_node = t_node->next;
    }
    return (min);
}

static void sort_3(t_node **t_node_a)
{
    int min = get_min(*t_node_a, -1);
    int next_min = get_min(*t_node_a, min);

    if (is_stack_sorted(*t_node_a))
        return;
    if ((*t_node_a)->index == min && (*t_node_a)->next->index != next_min)
    {
        ra(t_node_a);
        sa(t_node_a);
        rra(t_node_a);
    }
    else if ((*t_node_a)->index == next_min)
    {
        if ((*t_node_a)->next->index == min)
            sa(t_node_a);
        else
            rra(t_node_a);
    }
    else
    {
        if ((*t_node_a)->next->index == min)
            ra(t_node_a);
        else
        {
            sa(t_node_a);
            rra(t_node_a);
        }
    }
}

static void sort_4_5(t_node **t_node_a, t_node **t_node_b, int size)
{
    int distance;

    while (stack_size(*t_node_a) > 3)
    {
        distance = get_distance(*t_node_a, get_min(*t_node_a, -1));
        if (distance == 1)
            ra(t_node_a);
        else if (distance == 2)
        {
            ra(t_node_a);
            ra(t_node_a);
        }
        else if (distance == 3 && size == 5)
        {
            rra(t_node_a);
            rra(t_node_a);
        }
        else
            rra(t_node_a);
        pb(t_node_a, t_node_b);
    }
    sort_3(t_node_a);
    while (stack_size(*t_node_b))
        pa(t_node_a, t_node_b);
}

void small_sort(t_node **t_node_a, t_node **t_node_b)
{
    int size = stack_size(*t_node_a);

    if (is_stack_sorted(*t_node_a) || size <= 1)
        return;
    if (size == 2)
        sa(t_node_a);
    else if (size == 3)
        sort_3(t_node_a);
    else if (size == 4 || size == 5)
        sort_4_5(t_node_a, t_node_b, size);
}

int stack_size(t_node *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}
