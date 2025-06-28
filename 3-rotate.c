/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:45:31 by brmaria-          #+#    #+#             */
/*   Updated: 2025/06/28 20:19:18 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	if(!stack || !(*stack)->content)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = find_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	write (1, "ra\n", 3);
}

void	do_rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	write (1, "rb\n", 3);
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write (1, "rr\n", 3);
}