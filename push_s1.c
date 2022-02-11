/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:01:49 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 19:00:05 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(t_node **stack2, t_node **stack1)
{
	t_node	*ptr;

	ptr = *stack2;
	(*stack2) = (*stack2)->next;
	ptr->next = NULL;
	ft_lstadd_front(stack1, ptr);
	write (1, "pa\n", 3);
}

void	push_ra(t_node **stack1)
{
	t_node	*ptr;
	t_node	*last;

	last = *stack1;
	ptr = *stack1;
	while (last->next)
		last = last->next;
	ptr = ptr->next;
	last->next = *stack1;
	(*stack1)->prev = last;
	(*stack1)->next = NULL;
	*stack1 = ptr;
	write(1, "ra\n", 3);
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
	write(1, "rra\n", 4);
}

void	push_sa(t_node **stack1)
{
	t_node	*ptr;
	int		tmp;

	ptr = *stack1;
	ptr = ptr->next;
	tmp = (*stack1)->data;
	(*stack1)->data = ptr->data;
	ptr->data = tmp;
	write(1, "sa\n", 3);
}
