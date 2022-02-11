/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:33:01 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:19:25 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_node **stack1, t_node **stack2)
{
	int	h;
	int	i;

	h = -1;
	i = getindex(*stack1, getmin(*stack1));
	if (getlen(*stack1) == 4)
		h = 0;
	while (getlen(*stack1) > 3)
	{
		i = getindex(*stack1, getmin(*stack1));
		if (i == 1)
			push_pb(stack1, stack2);
		else if (getlen(*stack1) / 2 + 1 <= i)
		{
			while (i++ <= getlen(*stack1))
				push_rra(stack1);
			push_pb(stack1, stack2);
		}
		else
			push_sa(stack1);
	}
	sort3(stack1);
	while (++h < 2)
		push_pa(stack2, stack1);
}
