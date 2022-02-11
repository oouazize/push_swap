/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:59:48 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:52:35 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort100(t_node **stack1, t_node **stack2)
{
	t_vars	*var;

	indexi(stack1);
	var = (t_vars *)malloc(sizeof(t_vars));
	var->top = *stack1;
	var->down = to_the_last(stack1);
	var->size = getlen(*stack1);
	part1(stack1, stack2, &var);
	sort5(stack1, stack2);
	var->down = to_the_last(stack1);
	var->down->data = -1;
	while (getlen(*stack2))
		part2(stack1, stack2, &var);
	while ((*stack1)->data != 0)
		push_rra(stack1);
	free(var);
}

void	sort500(t_node **stack1, t_node **stack2)
{
	t_vars	*var;

	indexi(stack1);
	var = (t_vars *)malloc(sizeof(t_vars));
	var->top = *stack1;
	var->down = to_the_last(stack1);
	var->size = getlen(*stack1);
	part1_(stack1, stack2, &var);
	sort5(stack1, stack2);
	var->down = to_the_last(stack1);
	var->down->data = -1;
	while (getlen(*stack2))
		part2_(stack1, stack2, &var);
	while ((*stack1)->data != 0)
		push_rra(stack1);
	free(var);
}
