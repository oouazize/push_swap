/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrgsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:05:13 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 18:04:02 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	combine(int arr[], int s, int m, int e)
{
	int	*buff;
	int	j;
	int	i;
	int	k;

	buff = (int *)malloc(sizeof(int) * e + 1);
	k = s - 1;
	while (++k <= e)
		buff[k] = arr[k];
	i = s;
	j = m + 1;
	k = s;
	while (i <= m && j <= e)
	{
		if (buff[i] <= buff[j])
			arr[k++] = buff[i++];
		else
			arr[k++] = buff[j++];
	}
	while (i <= m)
		arr[k++] = buff[i++];
	while (j <= e)
		arr[k++] = buff[j++];
	free(buff);
}

void	mrgsort(int arr[], int s, int e)
{
	int	m;

	if (s < e)
	{
		m = (s + e) / 2;
		mrgsort(arr, s, m);
		mrgsort(arr, m + 1, e);
		combine(arr, s, m, e);
	}
}
