/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:28:46 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/16 17:43:02 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
} */

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
		free(tmp->content);  // Si content es un puntero dinámico, hay que liberarlo
		free(tmp);
	}
	*stack = NULL;  // Asegurarse de que el puntero quede NULL
}
