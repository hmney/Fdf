/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:31:43 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 18:15:20 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	fill_pixel(t_fdf *store, t_point point, t_rgb color)
{
	int position;

	if (point.x >= 0 && point.y >= 0 && point.x < IMG_WIDTH &&
			point.y < IMG_HEIGHT)
	{
		position = 4 * (IMG_WIDTH * point.y + point.x);
		store->img[position] = (char)color.r;
		store->img[position + 1] = (char)color.g;
		store->img[position + 2] = (char)color.b;
	}
}

void	bresenham(t_fdf store, t_point first, t_point second)
{
	t_bresenham var;

	var.delta_x = abs(second.x - first.x);
	var.delta_y = abs(second.y - first.y);
	var.sx = (first.x < second.x) ? 1 : -1;
	var.sy = (first.y < second.y) ? 1 : -1;
	var.error = ((var.delta_x > var.delta_y) ? var.delta_x : -var.delta_y) / 2;
	while (1)
	{
		fill_pixel(&store, first, get_color(first));
		if (first.x == second.x && first.y == second.y)
			break ;
		var.error2 = var.error;
		if (var.error2 > -var.delta_x)
		{
			var.error -= var.delta_y;
			first.x += var.sx;
		}
		if (var.error2 < var.delta_y)
		{
			var.error += var.delta_x;
			first.y += var.sy;
		}
	}
}

void	draw_line(t_fdf store, t_point first, t_point second)
{
	if (store.projection == 'I')
	{
		isometric_projection(store, &first.x, &first.y, first.z);
		isometric_projection(store, &second.x, &second.y, second.z);
	}
	if (store.translation_x != 0)
	{
		translation_x(store, &first.x);
		translation_x(store, &second.x);
	}
	if (store.translation_y != 0)
	{
		translation_y(store, &first.y);
		translation_y(store, &second.y);
	}
	bresenham(store, first, second);
}

t_point	equal(int x, int y, int z)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

void	trace_map(t_fdf s)
{
	s.i = -1;
	s.scaling.y = s.start.y;
	while (++s.i < s.max_height)
	{
		s.j = -1;
		s.scaling.x = s.start.x;
		while (++s.j < s.max_width)
		{
			s.first = equal(s.scaling.x, s.scaling.y, s.stock[s.i][s.j].z);
			if (s.j + 1 < s.max_width)
			{
				s.second = equal(s.scaling.x + s.scale, s.scaling.y,
						s.stock[s.i][s.j + 1].z);
				draw_line(s, s.first, s.second);
			}
			if (s.i + 1 < s.max_height)
			{
				s.second = equal(s.scaling.x, s.scaling.y + s.scale,
						s.stock[s.i + 1][s.j].z);
				draw_line(s, s.first, s.second);
			}
			s.scaling.x += s.scale;
		}
		s.scaling.y += s.scale;
	}
}
