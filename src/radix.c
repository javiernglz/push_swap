/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:51:38 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/04 23:44:39 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int get_max_bits(t_node *stack)
{
    t_node *head;
    int max;
    int max_bits;

    if (!stack)
        return (0);

    head = stack;
    max = head->index;
    max_bits = 0;
    
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    
    while ((max >> max_bits) != 0)
        max_bits++;
    
    return (max_bits);
}

int	is_stack_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
