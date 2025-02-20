/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:51:38 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 21:45:58 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void normalized_indice(t_node *stack, int size)
{
    int *arr = malloc(size * sizeof(int));
    if (!arr)
        return;
    
    t_node *tmp = stack;
    for (int i = 0; i < size; i++)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
    }
    
    // Ordenar el array
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Asignar índices a los valores
    tmp = stack;
    while (tmp)
    {
        for (int i = 0; i < size; i++)
        {
            if (tmp->value == arr[i])
            {
                tmp->value = i;
                break;
            }
        }
        tmp = tmp->next;
    }
    free(arr);
}

int is_stack_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void radix_sort(t_stack *stack, int size)
{
    int bit_size = 0;
    int max_num = size - 1;
   // t_node *tmp;

    while (max_num > 0)
    {
        bit_size++;
        max_num >>= 1;
    }

    for (int j = 0; j < bit_size; j++)
    {
        int i = size;
        while (i--)
        {
            if (((stack->a->value >> j) & 1) == 0)
                push(&stack->a, &stack->b);
            else
                rotate(&stack->a);
        }

        while (stack->b)
            push(&stack->b, &stack->a);
    }
}
