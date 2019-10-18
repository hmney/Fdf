/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:35:37 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 14:33:40 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	isometric_projection(t_fdf store, int *x, int *y, int z)
{
	int copie_x;
	int copie_y;

	copie_x = *x;
	copie_y = *y;
	*x = (copie_x - copie_y) * cos(0.523599);
	*y = (copie_x + copie_y) * sin(0.523599) - store.altitude * z;
}

void	translation_x(t_fdf store, int *x)
{
	*x += store.translation_x;
}

void	translation_y(t_fdf store, int *y)
{
	*y += store.translation_y;
}
