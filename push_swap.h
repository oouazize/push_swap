/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:13:33 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 18:00:01 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct node
{
	struct node	*prev;
	int			data;
	struct node	*next;
}				t_node;

typedef struct vars
{
	int		pushed;
	int		min;
	int		max;
	int		med;
	int		size;
	int		goal;
	int		meddleb;
	t_node	*top;
	t_node	*down;
}				t_vars;

// typedef struct mrg
// {
// 	int	med;
// 	int	k;
// 	int	i;
// 	int	j;
// }				t_mrg;

int		ft_atoi(const char *str);
t_node	*ft_lstnew(int data);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	check_error(int arc, char *arv[]);
void	radix(t_node **lst);
void	sort3(t_node **Stack1);
void	sort5(t_node **Stack1, t_node **Stack2);
int		getmax(t_node *lst);
int		getlen(t_node *Stack1);
int		getmin(t_node *lst);
int		getindex(t_node *lst, int n);
void	sort10(t_node **Stack1, t_node **Stack2);
void	sort100(t_node **StackA, t_node **StackB);
void	mrgsort(int arr[], int s, int e);
void	push_sa(t_node **Stack1);
void	push_sb(t_node **s2);
void	push_pa(t_node **Stack1, t_node **Stack2);
void	push_pb(t_node **Stack1, t_node **Stack2);
void	push_ra(t_node **Stack1);
void	push_rb(t_node **Stack2);
void	push_rra(t_node **Stack1);
void	push_rrb(t_node **Stack2);
void	push_ss(t_node **Stack1, t_node **s2);
void	push_rr(t_node **Stack2, t_node **Stack1);
void	push_rrr(t_node **Stack1, t_node **Stack2);
int		check(t_node *lst, int min, int max);
int		indexarr(int arr[], int n, int len);
void	sort500(t_node **StackA, t_node **StackB);
t_node	*to_the_last(t_node **stack_a);
int		isthere(t_node *StackB, int n);
void	indexi(t_node **StackA);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	part11(t_node **stack1, t_node **stack2, t_vars **var);
void	part12(t_node **stack1, t_node **stack2, t_vars **var);
void	part1(t_node **stack1, t_node **stack2, t_vars **var);
void	part21(t_node **stack1, t_node **stack2, t_vars **var);
void	part2(t_node **stack1, t_node **stack2, t_vars **var);
void	part11_(t_node **stack1, t_node **stack2, t_vars **var);
void	part12_(t_node **stack1, t_node **stack2, t_vars **var);
void	part1_(t_node **stack1, t_node **stack2, t_vars **var);
void	part21_(t_node **stack1, t_node **stack2, t_vars **var);
void	part2_(t_node **stack1, t_node **stack2, t_vars **var);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
