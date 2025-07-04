/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:59:22 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 18:13:39 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_bits(t_list **stack_b, t_list **stack_a, int index, int n)
{
	if ((index >> n) & 1)
	{
		do_ra(stack_a);
	}
	else
	{
		do_pb(stack_b, stack_a);
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	get_max_bits(t_list *stack)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int	max_bits;
	int	j;
	int	n;

	ft_index(*stack_a);
	if(is_ordenate(*stack_a))
		return ;
	max_bits = get_max_bits(*stack_a);
	n = 0;
	if ((stack_size == 10) || (stack_size == 3)
		|| (stack_size == 5) || (stack_size == 2))
		sort_tiny(stack_a, stack_b, stack_size);
	else
	{
		while (n < max_bits)
		{
			j = -1;
			while (++j < stack_size)
				check_bits(stack_b, stack_a, (*stack_a)->index, n);
			while (ft_lstsize(*stack_b))
				do_pa(stack_a, stack_b);
			n++;
		}
	}
}
