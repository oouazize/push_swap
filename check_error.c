/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:20:16 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/10 13:05:19 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dpl2(char **str, int j, int i)
{
	int	k;

	k = 1;
	while (str[k])
	{
		if (k == i)
			k++;
		else
		{
			if (ft_atoi(str[k]) == j)
			{
				write(1, "Error", 5);
				exit (0);
			}
			else
				k++;
		}
	}
}

void	check_dpl(char *str[])
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = ft_atoi(str[i]);
		check_dpl2(str, j, i);
		i++;
	}
}

void	check_error(int arc, char *arv[])
{
	if (arc == 1)
		exit (0);
	check_dpl(arv);
}
