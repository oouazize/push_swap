/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rr_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:39:32 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 09:23:16 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_rrr(t_node **stack1, t_node **stack2)
{
	push_rra(stack1);
	push_rrb(stack2);
}

void	push_rr(t_node **stack2, t_node **stack1)
{
	push_ra(stack1);
	push_rb(stack2);
}
