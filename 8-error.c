/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8-error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:54:44 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 17:35:55 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	ft_error(char **args, t_list *a, t_list *b, int argc)
{
	write(2, "Error\n", 6);
	if (argc == 2)
		free_split(args);
	free_stack(a);
	free_stack(b);
	exit(1);
}
