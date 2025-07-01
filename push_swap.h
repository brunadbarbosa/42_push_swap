#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list 
{
	struct s_list	*next;
	int				content;
	int				index;
}					t_list;

int	 correct_input(char **str, int count);
int	is_valid(char *str);
long	ft_atol(char *str);
t_list	*find_stack_bottom(t_list *stack);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*fill_list(char **argv, int count);
void	ft_swap(t_list *stack);
void	do_sa(t_list **stack_a);
void	do_sb(t_list **stack_b);
void	do_ss(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack);
void	do_ra(t_list **stack_a);
void	do_rb(t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b);
t_list	*find_before_bottom(t_list *stack);
void	ft_reverse_rotate(t_list **stack);
void	do_rra(t_list **stack_a);
void	do_rrb(t_list **stack_b);
void	do_rrr(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_src, t_list **stack_dest);
void	do_pa(t_list **stack_a, t_list **stack_b);
void	do_pb(t_list **stack_b, t_list **stack_a);

#endif