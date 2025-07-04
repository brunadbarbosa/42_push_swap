/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-indexation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:03:45 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 18:13:12 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *numbers, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	is_ordenate(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static void	index_list(int *numbers, t_list *stack_a, int count)
{
	int		i;
	t_list	*temp;

	temp = stack_a;
	while (temp)
	{
		i = 0;
		while (i <= count)
		{
			if (temp->content == numbers[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}



void	ft_index(t_list *stack_a)
{
	int		numb[2048];
	t_list	*temp;
	int		i;

	i = 0;
	temp = stack_a;
	while (temp)
	{
		numb[i] = temp->content;
		i++;
		temp = temp->next;
	}
	sort_array(numb, i);
	index_list(numb, stack_a, i);
}
