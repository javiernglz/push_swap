/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:42 by frnavarr          #+#    #+#             */
/*   Updated: 2025/03/07 01:02:24 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* static void	initStack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		int *value = malloc(sizeof(int));
		if (!value)
		{
			ft_putstr_fd("Error: No se pudo asignar memoria.\n", 2);
			exit(1);
		}
		*value = ft_atoi(args[i]);
		new = ft_lstnew(value);
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initStack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
} */

static void initStack(t_list **stack, int argc, char **argv)
{
    int i;
    t_list *new;

    *stack = NULL;
    for (i = 1; i < argc; i++)
    {
		int *value = malloc(sizeof(int));  // Asegúrate de usar malloc para almacenar un entero
		if (!value)
		{
			printf("Error de memoria\n");
			return;
		}
		*value = ft_atoi(argv[i]);  // Almacenar el valor entero en el puntero
		new = ft_lstnew(value);  // Pasar el puntero a la función
				if (!new)
        {
            printf("Error al crear nodo\n");
            return;
        }
        ft_lstadd_back(stack, new);  // Agregar al final de la pila
    }
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    
    if (argc < 2)
    {
        printf("Uso: %s <números a ordenar>\n", argv[0]);
        return 1;
    }

    stack_a = NULL;
    stack_b = NULL;

    // Inicializa la pila A
    initStack(&stack_a, argc, argv);

    // Imprime la pila A antes de ordenar
    printf("Pila A antes de ordenar:\n");
    print_stack(stack_a);

    // Indexa la pila A
    index_stack(&stack_a);

    // Aquí puedes agregar el código para ordenar las pilas (como el algoritmo de push_swap)
    // Ejemplo: simple_sort(stack_a, stack_b);

    // Imprime la pila A después de ordenar
    printf("Pila A después de ordenar:\n");
    print_stack(stack_a);

    // Imprime la pila B (si se usó)
    printf("Pila B:\n");
    print_stack(stack_b);

    // Liberar la memoria de las pilas (implementa tu función de liberar las pilas)
    // free_stack(stack_a);
    // free_stack(stack_b);

    return 0;
}
