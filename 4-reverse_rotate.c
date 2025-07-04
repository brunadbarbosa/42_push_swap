/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:20:15 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/03 15:26:11 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	if (!*stack || !(*stack)->content)
		return ;
	tail = find_stack_bottom(*stack);
	before_tail = find_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	do_rrb(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
