/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:23:28 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/03 15:39:15 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	do_sa(t_list **stack_a)
{
	ft_swap(*stack_a);
	write (1, "sa\n", 3);
}

void	do_sb(t_list **stack_b)
{
	ft_swap(*stack_b);
	write (1, "sb\n", 3);
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	write (1, "ss\n", 3);
}
