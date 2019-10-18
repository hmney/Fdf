/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:37:37 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 18:12:22 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	store;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(store.mlx_ptr = mlx_init()))
			return (EXIT_FAILURE);
		if (!(store.win_ptr = mlx_new_window(store.mlx_ptr, WIN_WIDTH,
						WIN_HEIGHT, "FDF")))
			return (EXIT_FAILURE);
		store_positions(&store, fd);
		initialisation(&store);
		mlx_hook(store.win_ptr, 2, 0, key_press, &store);
		mlx_loop(store.mlx_ptr);
		close(fd);
	}
	else
		ft_putendl("usage: ./fdf file_map");
	return (0);
}
