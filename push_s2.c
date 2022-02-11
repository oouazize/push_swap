/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:04:41 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/10 12:16:36 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pb(t_node **stack1, t_node **stack2)
{
	t_node	*ptr;

	write (1, "pb\n", 3);
	ptr = *stack1;
	(*stack1) = (*stack1)->next;
	(*stack1)->prev = NULL;
	ptr->next = NULL;
	ptr->prev = NULL;
	ft_lstadd_front(stack2, ptr);
}

void	push_rb(t_node **stack2)
{
	t_node	*ptr;
	t_node	*last;

	if (getlen(*stack2) <= 1)
		return ;
	last = *stack2;
	ptr = *stack2;
	while (last->next)
		last = last->next;
	ptr = ptr->next;
	last->next = *stack2;
	(*stack2)->prev = last;
	(*stack2)->next = NULL;
	*stack2 = ptr;
	(*stack2)->prev = NULL;
	write(1, "rb\n", 3);
}

void	push_rrb(t_node **stack2)
{
	t_node	*last;
	t_node	*prev;

	last = *stack2;
	prev = *stack2;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	last->next = *stack2;
	(*stack2)->prev = last;
	prev->next = NULL;
	*stack2 = last;
	write(1, "rrb\n", 4);
}

void	push_sb(t_node **s2)
{
	t_node	*ptr;
	int		tmp;

	ptr = *s2;
	ptr = ptr->next;
	tmp = (*s2)->data;
	(*s2)->data = ptr->data;
	ptr->data = tmp;
	write(1, "sb\n", 3);
}
