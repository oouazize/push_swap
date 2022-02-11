/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:24:15 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:24:13 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_sort(t_node *s1, t_node *s2)
{
	if (s2)
	{
		write(1, "KO\n", 3);
		exit (0);
	}
	while (s1->next)
	{
		if (s1->data > s1->next->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		else
			s1 = s1->next;
	}
	write(1, "OK\n", 3);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*first;
	unsigned char	*second;

	i = 0;
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (1);
		i++;
	}
	return (0);
}

void	operations(char *line, t_node **stack1, t_node **stack2)
{
	if (ft_strcmp(line, "rra") == 0)
		push_rra(stack1);
	else if (ft_strcmp(line, "ra") == 0)
		push_ra(stack1);
	else if (ft_strcmp(line, "sa") == 0)
		push_sa(stack1);
	else if (ft_strcmp(line, "sb") == 0)
		push_sb(stack2);
	else if (ft_strcmp(line, "pa") == 0)
		push_pa(stack2, stack1);
	else if (ft_strcmp(line, "pb") == 0)
		push_pb(stack1, stack2);
	else if (ft_strcmp(line, "rb") == 0)
		push_rb(stack2);
	else if (ft_strcmp(line, "rrb") == 0)
		push_rrb(stack2);
	else if (ft_strcmp(line, "ss") == 0)
		push_ss(stack1, stack2);
	else if (ft_strcmp(line, "rrr") == 0)
		push_rrr(stack1, stack2);
	else if (ft_strcmp(line, "rr") == 0)
		push_rr(stack1, stack2);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 32)
			return (1);
		i++;
	}
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
		&& ft_strcmp(line, "ra") && ft_strcmp(line, "rra")
		&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb")
		&& ft_strcmp(line, "rb") && ft_strcmp(line, "rrb")
		&& ft_strcmp(line, "rr") && ft_strcmp(line, "ss")
		&& ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

int	main(int arc, char *arv[])
{
	t_node	*stack1;
	t_node	*stack2;
	t_node	*new;
	char	*input;

	check_error(arc, arv);
	while (--arc > 0)
	{
		new = ft_lstnew(ft_atoi(arv[arc]));
		ft_lstadd_front(&stack1, new);
	}
	input = get_next_line(0);
	while (input)
	{
		if (check_line(input))
		{
			write(1, "Error", 5);
			exit (0);
		}
		operations(input, &stack1, &stack2);
		free(input);
		input = get_next_line(0);
	}
	check_sort(stack1, stack2);
}
