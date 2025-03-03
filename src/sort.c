/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:34:52 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/03 10:11:49 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int value)
{
    t_node	*node = malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	return (node);
}