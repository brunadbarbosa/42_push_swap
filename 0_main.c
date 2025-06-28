#include "push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	int	n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * n) > INT_MAX || (result * n) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (result * n);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0' || (str[i] == '-' || str[i] == '+'))
		return (1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	 correct_input(char **str, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		if (is_valid(str[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while(j < count)
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

int	main (int argc, char **argv)
{
    t_list	*stack_a;
	t_list	*stack_b;

    if (argc > 2)
    {
		stack_a = NULL;
		stack_b = NULL;
		if (correct_input(argv + 1, argc - 1) == 0)
		{
			stack_a = fill_list(argv + 1 , argc - 1);
			if (!stack_a)
			{
				write (2, "Error\n", 6);
				return (1);
			}
		}
		else
		{
			write (2, "Error\n", 6);
			return (1);
		}
	}
    return (0);
}
