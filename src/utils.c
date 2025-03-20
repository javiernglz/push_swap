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
		stack = stack->next;
}

void arguments(int argc, char **argv)
{
    int i;
    long tmp;
    char **args;    

    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv + 1;

    i = 0;
    while (args[i])
    {
        tmp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]) || ft_contains(tmp, args, i) || tmp < -2147483648 || tmp > 2147483647)
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
    if (argc == 2)
        ft_free(args);
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
