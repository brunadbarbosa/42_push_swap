/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:23:28 by brmaria-          #+#    #+#             */
/*   Updated: 2025/06/30 16:32:33 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_swap(t_list *stack)
{
	int	tmp;

	if(!stack || !stack->next)
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