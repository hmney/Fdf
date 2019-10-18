/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:26:41 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 18:27:17 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	get_color2(t_point first, t_rgb *color)
{
	if (first.z >= 10 && first.z < 20)
	{
		color->r = 0;
		color->g = 0;
		color->b = 128;
	}
	else if (first.z >= 20 && first.z < 30)
	{
		color->r = 255;
		color->g = 0;
		color->b = 0;
	}
	else
	{
		color->r = 255;
		color->g = 255;
		color->b = 0;
	}
}

t_rgb	get_color(t_point first)
{
	t_rgb color;

	if (first.z < 0)
	{
		color.r = 0;
		color.g = 128;
		color.b = 0;
	}
	else if (first.z == 0)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
	}
	else if (first.z > 0 && first.z < 10)
	{
		color.r = 128;
		color.g = 0;
		color.b = 0;
	}
	else
		get_color2(first, &color);
	return (color);
}
