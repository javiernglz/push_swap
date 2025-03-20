/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:42 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/20 22:39:27 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void initStack(t_list **stack, int argc, char **argv)
{
    int i;
    t_list *new;

    *stack = NULL;
    for (i = 1; i < argc; i++)
    {
		int *value = malloc(sizeof(int));
		if (!value)
		{
			printf("Memory Error\n");
			return;
		}
		*value = ft_atoi(argv[i]);
		new = ft_lstnew(value);
				if (!new)
        {
            printf("Error creating the node\n");
            return;
        }
        ft_lstadd_back(stack, new);
    }
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    
    if (argc < 2)
    {
        printf("Uso: %s <números a ordenar>\n", argv[0]);
        return (1);
    }

    stack_a = NULL;
    stack_b = NULL;

    initStack(&stack_a, argc, argv);

    if (!stack_a)
    {
        printf("Error initializing the stack\n");
        return (1);
    }

    index_stack(&stack_a);
    radix_sort(&stack_a, &stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}
