/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:13:21 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 20:47:36 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

void	error(void)
{
	write(1, "Error", 5);
	exit (0);
}

void	non_numeric(const char *str, int j)
{
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			error();
		j++;
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	i = ft_isspace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		error();
	non_numeric(str, i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (sign * res > 2147483647 || sign * res < -2147483648)
			error();
	}
	return (sign * res);
}
