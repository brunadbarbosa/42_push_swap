/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:37:39 by brmaria-          #+#    #+#             */
/*   Updated: 2025/06/28 20:48:14 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_reverse_rotate(t_list **stack_src, t_list **stack_dest)
{
	t_list	*tmp;


	if(!*stack_src)
		return ;
	tmp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = tmp;
}

void	do_pa(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_b, stack_a);
	write (1, "pa\n", 3);
}

void	do_pb(t_list **stack_b, t_list **stack_a)
{
	ft_reverse_rotate(stack_a, stack_b);
	write (1, "pb\n", 3);
}
