/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:16:45 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:53:45 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmax(t_node *lst)
{
	t_node	*tmp;
	int		mx;

	mx = lst->data;
	tmp = lst;
	tmp = lst->next;
	while (tmp)
	{
		if (tmp->data > mx)
			mx = tmp->data;
		tmp = tmp->next;
	}
	return (mx);
}

int	getmin(t_node *lst)
{
	int	small;

	small = lst->data;
	while (lst)
	{
		if (lst->data < small)
			small = lst->data;
		lst = lst->next;
	}
	return (small);
}

t_node	*to_the_last(t_node **stack_a)
{
	t_node	*temp;

	temp = (*stack_a);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	check_sort(t_node *new)
{
	int	x;

	x = 0;
	while (new->next)
	{
		if (new->data > new->next->data)
		{
			x = 1;
			break ;
		}
		else
			new = new->next;
	}
	if (!x)
		exit (0);
}

int	main(int arc, char *arv[])
{
	t_node	*stack1;
	t_node	*stack2;
	t_node	*new;
	int		size;

	stack2 = NULL;
	size = arc - 1;
	check_error(arc, arv);
	while (size > 0)
	{
		new = ft_lstnew(ft_atoi(arv[size]));
		ft_lstadd_front(&stack1, new);
		size--;
	}
	check_sort(stack1);
	if (arc <= 2)
		exit(0);
	else if (arc <= 4)
		sort3(&stack1);
	else if (arc <= 6)
		sort5(&stack1, &stack2);
	else if (arc <= 101)
		sort100(&stack1, &stack2);
	else
		sort500(&stack1, &stack2);
}
