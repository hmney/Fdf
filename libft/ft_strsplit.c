/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:09:57 by hmney             #+#    #+#             */
/*   Updated: 2019/01/11 12:24:21 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(char const *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static int		count_char(char const *str, int index, char c)
{
	int counter;

	counter = 0;
	while (str[index] != '\0' && str[index] != c)
	{
		index++;
		counter++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (words(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			size = count_char(s, i, c);
			tab[j] = ft_strsub(s, (unsigned int)i, (size_t)size);
			j++;
			i += size;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
