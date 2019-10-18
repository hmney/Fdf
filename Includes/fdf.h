/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:25:02 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 17:31:04 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <math.h>
# include "mlx_keys.h"
# define BUFF_SIZE 300000
# define IMG_WIDTH 1780
# define IMG_HEIGHT 1480
# define WIN_WIDTH 1780
# define WIN_HEIGHT 1480

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_array
{
	int		z;
	t_rgb	rgb;
}				t_array;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_fdf
{
	t_array **stock;
	char	*img;
	int		max_width;
	int		max_height;
	int		scale;
	int		projection;
	int		altitude;
	int		translation_x;
	int		translation_y;
	int		vitesse;
	int		i;
	int		j;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		bpp;
	int		s_l;
	int		endian;
	t_point	scaling;
	t_point	start;
	t_point	first;
	t_point	second;
}				t_fdf;

typedef struct	s_bresenham
{
	int delta_x;
	int delta_y;
	int error;
	int error2;
	int sx;
	int sy;
}				t_bresenham;

int				key_press(int key, t_fdf *store);
void			part_two(int key, t_fdf *store);
void			initialisation(t_fdf *store);
void			store_positions(t_fdf *store, int fd);
void			set_positions(t_fdf *store, char **tab, int i);
int				calcul_height(t_fdf *store, char **tab);
int				calcul_width(t_fdf *store, char *tab);
void			isometric_projection(t_fdf store, int *x, int *y, int z);
void			translation_x(t_fdf store, int *x);
void			translation_y(t_fdf store, int *y);
void			fill_pixel(t_fdf *store, t_point point, t_rgb color);
void			bresenham(t_fdf store, t_point first, t_point second);
void			draw_line(t_fdf store, t_point first, t_point second);
t_point			equal(int x, int y, int z);
void			trace_map(t_fdf s);
t_rgb			get_color(t_point first);
void			get_color2(t_point first, t_rgb *color);
int				calcul_scale(int x, int y);
#endif
