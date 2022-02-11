/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:40:03 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 18:35:13 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part11_(t_node **stack1, t_node **stack2, t_vars **var)
{
	while (check(*stack1, (*var)->min, (*var)->max) == 1)
		push_ra(stack1);
	push_pb(stack1, stack2);
	if ((*stack2)->data > (*var)->med)
		push_rb(stack2);
	(*var)->size--;
	(*var)->pushed--;
	(*var)->down = to_the_last(stack1);
	(*var)->top = *stack1;
}

void	part12_(t_node **stack1, t_node **stack2, t_vars **var)
{
	while (check(*stack1, (*var)->min, (*var)->max) == 1)
		push_rra(stack1);
	push_pb(stack1, stack2);
	if ((*stack2)->data > (*var)->med)
		push_rb(stack2);
	(*var)->size--;
	(*var)->pushed--;
	(*var)->down = to_the_last(stack1);
	(*var)->top = *stack1;
}

void	part1_(t_node **stack1, t_node **stack2, t_vars **var)
{
	(*var)->top = *stack1;
	(*var)->down = to_the_last(stack1);
	while ((*var)->size > 5)
	{
		(*var)->pushed = ((*var)->size - 5) / 5.5 + 1;
		(*var)->min = getmin(*stack1);
		(*var)->max = (*var)->min + (*var)->pushed - 1;
		(*var)->med = ((*var)->max + (*var)->min) / 2;
		while ((*var)->pushed > 0)
		{
			if ((*var)->top->data >= (*var)->min
				&& (*var)->top->data <= (*var)->max)
				part11(stack1, stack2, var);
			else if ((*var)->down->data >= (*var)->min
				&& (*var)->down->data <= (*var)->max)
				part12(stack1, stack2, var);
			else
			{
				(*var)->top = (*var)->top->next;
				(*var)->down = (*var)->down->prev;
			}
		}
	}
}

void	part21_(t_node **stack1, t_node **stack2, t_vars **var)
{
	(*var)->goal = getindex(*stack2, (*stack1)->data - 1);
	(*var)->meddleb = getlen(*stack2) / 2;
	while ((*stack1)->data - 1 != (*stack2)->data)
	{
		if ((*var)->goal > (*var)->meddleb)
			push_rrb(stack2);
		else
			push_rb(stack2);
	}
	push_pa(stack2, stack1);
}

void	part2_(t_node **stack1, t_node **stack2, t_vars **var)
{
	(*var)->down = to_the_last(stack1);
	if ((*stack1)->data - 1 == (*stack2)->data)
		push_pa(stack2, stack1);
	else
	{
		if (isthere(*stack2, (*stack1)->data - 1) == 1)
		{
			if ((*stack2)->data < (*stack1)->data
				&& (*stack2)->data > (*var)->down->data)
			{
				push_pa(stack2, stack1);
				push_ra(stack1);
			}
			else
				part21(stack1, stack2, var);
		}
		else
			push_rra(stack1);
	}
}
