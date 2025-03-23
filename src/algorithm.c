/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:01:28 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/23 20:23:36 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int stack_size(t_list *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}


static int	find_smallest_index(t_list **stack)
{
	t_list	*head;
	int		min;

	if (!stack || !*stack)
		return (-1);
	head = *stack;
	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		head = head->next;
	}
	return (min);
}

static void sort_3(t_list **stack_a)
{
	int a = (*stack_a)->index;
	int b = (*stack_a)->next->index;
	int c = (*stack_a)->next->next->index;

	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}
static void sort_4_5(t_list **stack_a, t_list **stack_b)
{
    int dist;
    int size;

    while (stack_size(*stack_a) > 3)
    {
        size = stack_size(*stack_a);
        dist = find_index_position(*stack_a, find_smallest_index(stack_a));
        
        if (dist <= size / 2)
        {
            while (dist-- > 0)
                ra(stack_a);
        }
        else
        {
            dist = size - dist;
            while (dist-- > 0)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
    }
    sort_3(stack_a);
    while (stack_size(*stack_b))
        pa(stack_a, stack_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size = ft_lstsize(*stack_a);

	if (is_sorted(stack_a) || size <= 1)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4 || size == 5)
		sort_4_5(stack_a, stack_b);
}
