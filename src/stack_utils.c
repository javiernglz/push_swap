/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:28:46 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/21 00:57:40 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	if (!stack || !*stack)
		return;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
	*stack = NULL;
}

static t_list *find_next_unindexed_min(t_list **stack)
{
	t_list *head = *stack;
    t_list *min = NULL;
	
    while (head)
    {
		if (head->index == -1)
        {
            if (!min || *((int *)head->content) < *((int *)min->content))
            {
                min = head;
            }
        }
        head = head->next;
    }

    return min;
}

void index_stack(t_list **stack)
{
	t_list *head;
	int index = 0;

	head = *stack;
	while (head)
	{
		head->index = -1;
		head = head->next;
	}
	while ((head = find_next_unindexed_min(stack))) 
		head->index = index++;
}

int	find_index_position(t_list *stack, int value)
{
	int	dist;

	dist = 0;
	while (stack)
	{
		if (stack->index == value)
			return (dist);
		stack = stack->next;
		dist++;
	}
	return (-1);
}
