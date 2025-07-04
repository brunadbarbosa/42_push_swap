/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.75-sort_tiny_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:49:53 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 17:35:03 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (0);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

static int	find_min(t_list *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	push_min_to_b(t_list **a, t_list **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->index != min)
		do_ra(a);
	do_pb(b, a);
}
