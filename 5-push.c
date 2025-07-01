/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:37:39 by brmaria-          #+#    #+#             */
/*   Updated: 2025/06/30 20:09:03 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_push(t_list **stack_src, t_list **stack_dest)
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
	ft_push(stack_b, stack_a);
	write (1, "pa\n", 3);
}

void	do_pb(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_a, stack_b);
	write (1, "pb\n", 3);
}
