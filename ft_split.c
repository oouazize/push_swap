/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:48:22 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/11 09:43:29 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_counter(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_word(s, c);
		s += i;
		if (i > 0)
			word++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		string;
	int		count;
	int		size;
	char	**tab;

	if (!s)
		return (0);
	string = ft_counter(s, c);
	tab = (char **)malloc((string + 1) * sizeof(char *));
	if (!tab)
		return (0);
	count = -1;
	while (++count < string)
	{
		while (*s && *s == c)
			s++;
		size = ft_word(s, c);
		tab[count] = (char *)malloc((size + 1) * sizeof(char));
		if (!tab[count])
			return (0);
		ft_strlcpy(tab[count], s, size + 1);
		s += size;
	}
	tab[string] = 0;
	return (tab);
}
