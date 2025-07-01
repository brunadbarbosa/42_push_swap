/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-fill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:55:19 by brmaria-          #+#    #+#             */
/*   Updated: 2025/06/30 23:25:05 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_stack_bottom(t_list *stack)
{
	while (stack && stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_list	*fill_list(char **argv, int count)
{
	int	i;
	t_list	*new_node;
	t_list	*stack;
	long	num;

	i = 0;
	num = 0;
	stack = NULL;
	while (i < count)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		new_node = ft_lstnew((int)num);
		if (!new_node)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return(stack);
}