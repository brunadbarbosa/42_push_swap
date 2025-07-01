/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:57:30 by brmaria-          #+#    #+#             */
/*   Updated: 2025/06/30 19:59:46 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	int	n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * n) > INT_MAX || (result * n) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (result * n);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0' || (str[i] == '-' || str[i] == '+'))
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	 correct_input(char **str, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		if (is_valid(str[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while(j < count)
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


#include "push_swap.h"
#include <stdio.h>

// Função para imprimir uma stack
void print_stack(t_list *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

// Cria stack A manualmente com valores para teste
t_list *create_test_stack(int *values, int size)
{
	t_list *stack = NULL;
	for (int i = 0; i < size; i++)
	{
		ft_lstadd_back(&stack, ft_lstnew(values[i]));
	}
	return stack;
}

int main(void)
{
	// Teste inicial: stack A com [3, 2, 1]
	int values[] = {3, 2, 1};
	t_list *stack_a = create_test_stack(values, 3);
	t_list *stack_b = NULL;

	printf("Estado inicial:\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	// Testando movimentos
	do_sa(&stack_a);  // Trocar 3 e 2
	print_stack(stack_a, 'A');

	do_pb(&stack_b, &stack_a);  // Push A → B
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	do_ra(&stack_a);  // Roda stack A
	print_stack(stack_a, 'A');

	do_rra(&stack_a); // Roda reverso stack A
	print_stack(stack_a, 'A');

	do_pa(&stack_a, &stack_b);  // Push B → A
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	// Libera memória no fim (opcional, mas boa prática)
	// ...

	return (0);
}

// int	main (int argc, char **argv)
// {
//     t_list	*stack_a;
// 	t_list	*stack_b;

//     if (argc > 2)
//     {
// 		stack_a = NULL;
// 		stack_b = NULL;
// 		if (correct_input(argv + 1, argc - 1) == 0)
// 		{
// 			stack_a = fill_list(argv + 1 , argc - 1);
// 			if (!stack_a)
// 			{
// 				write (2, "Error\n", 6);
// 				return (1);
// 			}
// 		}
// 		else
// 		{
// 			write (2, "Error\n", 6);
// 			return (1);
// 		}
// 	}
//     return (0);
// }
