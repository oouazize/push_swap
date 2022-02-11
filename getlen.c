/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:35:02 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 09:29:49 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getlen(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	check(t_node *lst, int min, int max)
{
	if (lst->data >= min && lst->data <= max)
		return (0);
	return (1);
}

int	isthere(t_node *stack2, int n)
{
	while (stack2)
	{
		if (stack2->data == n)
			return (1);
		stack2 = stack2->next;
	}
	return (0);
}
