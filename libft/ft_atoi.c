/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:43:58 by hmney             #+#    #+#             */
/*   Updated: 2018/11/08 21:03:06 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
	{
		sign = 1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		value = value * 10 + (*str - '0');
		++str;
	}
	return (sign * value);
}
