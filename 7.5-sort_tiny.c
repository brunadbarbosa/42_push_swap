/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.5-sort_tiny.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:00:33 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 17:33:50 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_list **a)
{
	do_sa(a);
}

static void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		do_sa(a);
	else if (first > second && second > third)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (first > second && second < third && first > third)
		do_ra(a);
	else if (first < second && second > third && first < third)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (first < second && second > third && first > third)
		do_rra(a);
}

static void	sort_five(t_list **a, t_list **b, int stack_size)
{
	if (stack_size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
	}
	else if (stack_size == 4)
		push_min_to_b(a, b);
	sort_three(a);
	do_pa(a, b);
	do_pa(a, b);
}

static void	sort_ten(t_list **a, t_list **b, int stack_size)
{
	int	i;

	i = 4;
	while (stack_size > 5)
	{
		if ((*a)->index < 5)
		{
			do_pb(b, a);
			stack_size--;
		}
		else
			do_ra(a);
	}
	sort_five(a, b, stack_size);
	while (i >= 0)
	{
		if ((*b)->index == i)
		{
			do_pa(a, b);
			i--;
		}
		else
			do_rb(b);
	}
}

void	sort_tiny(t_list **a, t_list **b, int stack_size)
{
	if (stack_size == 2)
		sort_two(a);
	else if (stack_size == 3)
		sort_three(a);
	else if (stack_size <= 5)
		sort_five(a, b, stack_size);
	else if (stack_size == 10)
		sort_ten(a, b, stack_size);
}
