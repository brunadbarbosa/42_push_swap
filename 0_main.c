#include "push_swap.h"

long	ft_atol(char *str)
{
	int	i;
	int	n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] <= 32)
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
	return (result * n);
}

void	err_mes(int n)
{
	if (n == 1)
	{
		write (1, "Error\n", 6);

	}
}
int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
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

int	correct_input(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (is_valid(str[i]) == 0)
			i++;
		else
			return (1);
	}
	return (0);
}
t_list	*ft_lstnew(int *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
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
	
}

int	main (int argc, char **argv)
{
    t_list	*stack_a;
	t_list	*stack_b;

    if (argc >= 2)
    {
		if (correct_input(argv + 1, argc - 1) == 0)
		{
			stack_b = NULL;
			stack_a = fill_list(argv + 1 , argc - 1);
		}
		else
		{
			err_mes(1);
			return (0);
		}
	}
    return (0);
}
