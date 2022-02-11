/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:04:41 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:04:13 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_pa(t_node **stack2, t_node **stack1)
{
	t_node	*ptr;

	if (getlen(*stack2) < 1)
		return ;
	ptr = *stack2;
	(*stack2) = (*stack2)->next;
	ptr->next = NULL;
	ft_lstadd_front(stack1, ptr);
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
}

void	push_rrb(t_node **stack2)
{
	t_node	*last;
	t_node	*prev;

	if (getlen(*stack2) <= 1)
		return ;
	last = *stack2;
	prev = *stack2;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	last->next = *stack2;
	(*stack2)->prev = last;
	prev->next = NULL;
	*stack2 = last;
}

void	push_sb(t_node **s2)
{
	t_node	*ptr;
	int		tmp;

	if (getlen(*s2) <= 1)
		return ;
	ptr = *s2;
	ptr = ptr->next;
	tmp = (*s2)->data;
	(*s2)->data = ptr->data;
	ptr->data = tmp;
}
