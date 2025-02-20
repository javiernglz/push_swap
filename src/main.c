/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:42 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/20 21:40:55 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Uso: %s <números>\n", argv[0]);
        return 1;
    }

    t_stack stack = {NULL, NULL};

    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);
        t_node *new = new_node(num);
        if (!new)
        {
            free_stack(stack.a);
            return 1;
        }
        new->next = stack.a;
        stack.a = new;
    }

    printf("Pila inicial: ");
    print_stack(stack.a);

    normalized_indice(stack.a, argc - 1);
    radix_sort(&stack, argc - 1);

    printf("Pila ordenada: ");
    print_stack(stack.a);

    free_stack(stack.a);
    return 0;
}