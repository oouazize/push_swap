/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getindex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:01:17 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:50:16 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getindex(t_node *lst, int n)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->data == n)
			return (i);
		lst = lst->next;
		i++;
	}
	return (0);
}

int	indexarr(int arr[], int n, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == n)
			return (i);
		i++;
	}
	return (0);
}

void	indexi(t_node **stack1)
{
	int		i;
	int		*arr;
	t_node	*ptr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * getlen(*stack1));
	ptr = *stack1;
	while (ptr)
	{
		arr[i++] = ptr->data;
		ptr = ptr->next;
	}
	mrgsort(arr, 0, getlen(*stack1) - 1);
	ptr = *stack1;
	while (ptr)
	{
		ptr->data = indexarr(arr, ptr->data, getlen(*stack1));
		ptr = ptr->next;
	}
	free(arr);
}
