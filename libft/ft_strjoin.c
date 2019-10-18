/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:28:15 by hmney             #+#    #+#             */
/*   Updated: 2018/11/09 00:35:00 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	if (len_s1 + len_s2 != 0)
	{
		str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (str != NULL)
		{
			ft_strcpy(str, (char *)s1);
			ft_strcat(str, (char *)s2);
			str[len_s1 + len_s2 + 1] = '\0';
			return (str);
		}
	}
	return (NULL);
}
