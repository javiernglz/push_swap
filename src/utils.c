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

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d ", *((int *)stack->content));
		stack = stack->next;
	}
	printf("\n");
}

void	make_top(t_list **stack, int distance)
{
	t_list	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_lstsize(head) - distance;
	if (distance <= (ft_lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}

int	get_distance(t_list *stack, int value)
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

void ft_check_args(int argc, char **argv)
{
    int i;
    long tmp;
    char **args;    

    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv + 1; // Evita el primer argumento (nombre del programa)

    i = 0;
    while (args[i])
    {
        tmp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]) || ft_contains(tmp, args, i) || tmp < -2147483648 || tmp > 2147483647)
            ft_error("Error");
        i++;
    }
    if (argc == 2)
        ft_free(args);
}


void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

static t_list *get_next_min(t_list **stack)
{
    t_list *head = *stack;
    t_list *min = NULL;

    printf("\nBuscando el siguiente mínimo...\n");

    while (head)
    {
        printf("Nodo actual - Valor: %d, Índice: %d\n", *((int *)head->content), head->index);

        if (head->index == -1)
        {
            if (!min || *((int *)head->content) < *((int *)min->content))
            {
                min = head;
                printf("Nuevo mínimo encontrado: %d\n", *((int *)min->content));
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

    // Inicializar todos los índices a -1
    head = *stack;
    while (head)
    {
        head->index = -1;
        head = head->next;
    }

    printf("\nAsignando índices...\n");

    while ((head = get_next_min(stack))) 
    {
        head->index = index++;
        printf("Asignado índice %d al valor %d\n", head->index, *((int *)head->content));
    }
}



void print_stack_index(t_list *stack)
{
    while (stack)
    {
        printf("Valor: %d, Índice: %d\n", *((int *)stack->content), stack->index);
        stack = stack->next;
    }
    printf("\n");
}
