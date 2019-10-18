/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:22:34 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 18:13:00 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int		calcul_scale(int x, int y)
{
	if (x + y <= 100)
		return (42);
	else if (x + y > 100 && x + y <= 150)
		return (12);
	else if (x + y > 150 && x + y <= 200)
		return (5);
	else
		return (1);
}

void	initialisation(t_fdf *store)
{
	store->scale = calcul_scale(store->max_width, store->max_height);
	store->start.x = WIN_WIDTH / 2;
	store->start.y = 100;
	store->altitude = 1;
	store->projection = 'I';
	store->translation_x = 0;
	store->translation_y = 0;
	store->vitesse = 5;
}

void	part_two(int key, t_fdf *store)
{
	if (key == KEY_PAD_5)
		store->altitude--;
	else if (key == KEY_UP)
		store->translation_y -= 20;
	else if (key == KEY_DOWN)
		store->translation_y += 20;
	else if (key == KEY_LEFT)
		store->translation_x -= 20;
	else if (key == KEY_RIGHT)
		store->translation_x += 20;
	else if (key == KEY_CAPSLOCK)
		store->vitesse /= 2;
	else if (key == KEY_SHIFT_LEFT)
		store->vitesse *= 2;
	else if (key == KEY_PAD_ADD)
		store->scale += store->vitesse;
	else if (key == KEY_PAD_SUB)
		store->scale -= store->vitesse;
}

int		key_press(int key, t_fdf *store)
{
	if (!(store->img_ptr = mlx_new_image(store->mlx_ptr, IMG_WIDTH,
					IMG_HEIGHT)))
		return (EXIT_FAILURE);
	store->img = mlx_get_data_addr(store->img_ptr, &(store->bpp), &(store->s_l),
			&(store->endian));
	if (key == KEY_P)
		store->projection = 'P';
	else if (key == KEY_I)
		store->projection = 'I';
	else if (key == KEY_ESCAPE)
	{
		free(store->stock);
		free(store->img);
		exit(0);
	}
	else if (key == KEY_PAD_8)
		store->altitude++;
	else
		part_two(key, store);
	trace_map(*store);
	mlx_put_image_to_window(store->mlx_ptr, store->win_ptr,
			store->img_ptr, 0, 0);
	mlx_destroy_image(store->mlx_ptr, store->img_ptr);
	return (0);
}
