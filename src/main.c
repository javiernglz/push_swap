/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:42 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/21 00:42:44 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static t_list	*create_node(char *arg, char **argv, int index)
{
	long	num;
	int		*value;
	t_list	*new;

	if (!is_valid_number(arg))
		error_exit();
	num = ft_atol(arg);
	if (num < -2147483648 || num > 2147483647 || has_duplicates(argv, index, num))
		error_exit();
	value = malloc(sizeof(int));
	if (!value)
		error_exit();
	*value = (int)num;
	new = ft_lstnew(value);
	if (!new)
	{
		free(value);
		error_exit();
	}
	return (new);
}

static void	init_stack(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list	*new;

	*stack = NULL;
	i = 1;
	while (i < argc)
	{
		new = create_node(argv[i], argv, i);
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argc, argv);
	if (!stack_a)
		error_exit();
	index_stack(&stack_a);
	radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

