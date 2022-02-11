/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:35:13 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/10 20:06:07 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_node **stack1)
{
	int		index;
	t_node	*down;

	if (getlen(*stack1) == 2)
	{
		if ((*stack1)->data > (*stack1)->next->data)
			push_sa(stack1);
		return ;
	}
	index = getindex(*stack1, getmax(*stack1));
	if (index == 1)
		push_ra(stack1);
	else if (index == 2)
		push_rra(stack1);
	down = *stack1;
	down = (*stack1)->next;
	if ((*stack1)->data > down->data)
		push_sa(stack1);
}
