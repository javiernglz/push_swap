/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:51:38 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/16 18:02:34 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
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

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    t_list  *head_a;
    int     i, j, size, max_bits;

    i = 0;
    head_a = *stack_a;
    size = ft_lstsize(head_a);
    max_bits = get_max_bits(stack_a);

    printf("Bits máximos: %d\n", max_bits);

    while (i < max_bits)
    {
        j = 0;
        printf("Iteración %d:\n", i);

        while (j++ < size)
        {
            head_a = *stack_a;
            if (((head_a->index >> i) & 1) == 1)
            {
                printf("Moviendo arriba: %d\n", head_a->index);
                ra(stack_a);
            }
            else
            {
                printf("Moviendo a B: %d\n", head_a->index);
                pb(stack_a, stack_b);
            }
        }

        printf("Pila A después de pasar bits:\n");
        print_stack_index(*stack_a);
        printf("Pila B:\n");
        print_stack_index(*stack_b);

        while (ft_lstsize(*stack_b) != 0)
        {
            pa(stack_a, stack_b);
        }

        i++;
    }
}
