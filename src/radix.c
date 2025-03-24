/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:51:38 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/24 16:31:39 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (*((int *)head->content) > *((int *)head->next->content))
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_stack_b(t_list **stack_a, t_list **stack_b, int bit_size, int j)
{
	int	size;

	size = ft_lstsize(*stack_b);
	while (size-- && j <= bit_size && !is_sorted(stack_a))
	{
		if ((((*stack_b)->index >> j) & 1) == 0)
			rb(stack_b);
		else
			pa(stack_a, stack_b);
	}
	if (is_sorted(stack_a))
	{
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = ft_lstsize(*stack_a);
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = ft_lstsize(*stack_a);
		while (size-- && !is_sorted(stack_a))
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		sort_stack_b(stack_a, stack_b, bit_size, j + 1);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
