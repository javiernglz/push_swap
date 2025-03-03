/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:38:59 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/03 10:15:01 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	free_stack(t_node *stack)
{
    t_node	*tmp;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	get_distance(t_node *stack, int value)
{
	int	distance;

	distance = 0;
	while (stack)
	{
		if (stack->index == value)
			return (distance);
		stack = stack->next;
		distance++;
	}
	return (-1);
}

t_node	*new_node(int value)
{
    t_node	*node = malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	return (node);
}