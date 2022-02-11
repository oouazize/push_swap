/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:01:49 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:03:44 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_pb(t_node **stack1, t_node **stack2)
{
	t_node	*ptr;

	if (getlen(*stack1) < 1)
		return ;
	ptr = *stack1;
	(*stack1) = (*stack1)->next;
	(*stack1)->prev = NULL;
	ptr->next = NULL;
	ptr->prev = NULL;
	ft_lstadd_front(stack2, ptr);
}

void	push_ra(t_node **stack1)
{
	t_node	*ptr;
	t_node	*last;

	if (getlen(*stack1) <= 1)
		return ;
	last = *stack1;
	ptr = *stack1;
	while (last->next)
		last = last->next;
	ptr = ptr->next;
	last->next = *stack1;
	(*stack1)->prev = last;
	(*stack1)->next = NULL;
	*stack1 = ptr;
}

void	push_rra(t_node **stack1)
{
	t_node	*last;
	t_node	*prev;

	last = *stack1;
	prev = *stack1;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	last->next = *stack1;
	(*stack1)->prev = last;
	prev->next = NULL;
	*stack1 = last;
}

void	push_sa(t_node **stack1)
{
	t_node	*ptr;
	int		tmp;

	if (getlen(*stack1) <= 1)
		return ;
	ptr = *stack1;
	ptr = ptr->next;
	tmp = (*stack1)->data;
	(*stack1)->data = ptr->data;
	ptr->data = tmp;
}

void	push_ss(t_node **stack1, t_node **s2)
{
	push_sa(stack1);
	push_sb(s2);
}
