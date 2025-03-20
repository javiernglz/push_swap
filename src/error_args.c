/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:16:22 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/21 00:22:24 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(char **args, int index, long num)
{
	int	j;

	j = index + 1;
	while (args[j])
	{
		if (ft_atoi(args[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

void	arguments(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	args = (argc == 2) ? ft_split(argv[1], ' ') : argv + 1;
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]) || (tmp = ft_atoi(args[i])) < -2147483648
			|| tmp > 2147483647 || has_duplicates(args, i, tmp))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
