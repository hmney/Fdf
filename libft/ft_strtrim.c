/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:57:20 by hmney             #+#    #+#             */
/*   Updated: 2018/10/12 11:53:27 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;

	if (s)
	{
		start = 0;
		end = ft_strlen(s) - 1;
		while (s[start] != '\0' && isspace(s[start]))
			start++;
		while (s[end] && isspace(s[end]) && end > start)
			end--;
		if ((str = (char *)malloc(sizeof(char) * (end - start + 1))) == NULL)
			return (NULL);
		str = ft_strsub(s, start, end - start + 1);
		return (str);
	}
	return (NULL);
}
