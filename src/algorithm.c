/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:01:28 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/20 23:14:04 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_smallest_index(t_list **stack, int val)
{
	t_list	*head;
    int		min;
	
	head = *stack;
	min = head->index;
    while (head->next)
    {
        head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
    }
    return (min);
}

static void sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = find_smallest_index(stack_a, -1);
	next_min = find_smallest_index(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void sort_4_5(t_list **t_list_a, t_list **t_list_b)
{
    int distance;
	int size = 0;
	
    while (stack_size(*t_list_a) > 3)
    {
        distance = find_index_position(*t_list_a, find_smallest_index(t_list_a, -1));
        if (distance == 1)
            ra(t_list_a);
        else if (distance == 2)
        {
            ra(t_list_a);
            ra(t_list_a);
        }
        else if (distance == 3 && size == 5)
        {
            rra(t_list_a);
            rra(t_list_a);
        }
        else
            rra(t_list_a);
        pb(t_list_a, t_list_b);
    }
    sort_3(t_list_a);
    while (stack_size(*t_list_b))
        pa(t_list_a, t_list_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4_5(stack_a, stack_b);
}

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
