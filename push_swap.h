/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:34:58 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 18:13:23 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	struct s_list	*next;
	int				content;
	int				index;
}					t_list;

int		correct_input(char **str, int count);
int		is_valid(char *str);
long	ft_atol(char *str);
t_list	*find_stack_bottom(t_list *stack);
t_list	*ft_lstnew(int content);
int		ft_word_count(const char *s1, char c);
char	**ft_split(char const *s, char c);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*fill_list(char **argv, int count);
void	do_sa(t_list **stack_a);
void	do_sb(t_list **stack_b);
void	do_ss(t_list **stack_a, t_list **stack_b);
void	do_ra(t_list **stack_a);
void	do_rb(t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b);
void	do_rra(t_list **stack_a);
void	do_rrb(t_list **stack_b);
void	do_rrr(t_list **stack_a, t_list **stack_b);
void	do_pa(t_list **stack_a, t_list **stack_b);
void	do_pb(t_list **stack_b, t_list **stack_a);
void	ft_index(t_list *stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b, int stack_size);
void	ft_error(char **args, t_list *a, t_list *b, int argc);
void	free_stack(t_list *stack);
void	free_split(char **split);
int		ft_lstsize(t_list *lst);
void	sort_tiny(t_list **a, t_list **b, int stack_size);
void	push_min_to_b(t_list **a, t_list **b);
void	*ft_calloc(size_t nmemb, size_t size);
int		is_ordenate(t_list *stack_a);

#endif