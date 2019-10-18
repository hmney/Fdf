/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:29:20 by hmney             #+#    #+#             */
/*   Updated: 2019/01/20 18:14:41 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int		calcul_width(t_fdf *store, char *tab)
{
	char	**tab2;
	int		width;

	tab2 = ft_strsplit(tab, ' ');
	width = 0;
	while (tab2[width])
		width++;
	store->max_width = width;
	return (width);
}

int		calcul_height(t_fdf *store, char **tab)
{
	int height;

	height = 0;
	while (tab[height])
		height++;
	store->max_height = height;
	return (height);
}

void	set_positions(t_fdf *store, char **tab, int i)
{
	int j;

	j = 0;
	while (tab[j])
	{
		store->stock[i][j].z = ft_atoi(tab[j]);
		j++;
	}
}

void	store_positions(t_fdf *store, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*stock;
	char	**tab;
	int		ret;

	stock = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	tab = ft_strsplit(stock, '\n');
	if (!(store->stock = (t_array **)malloc(sizeof(t_array *) *
					calcul_height(store, tab))))
		return ;
	ret = -1;
	while (tab[++ret])
	{
		if (!(store->stock[ret] = (t_array *)malloc(sizeof(t_array) *
						calcul_width(store, tab[ret]))))
			return ;
		set_positions(store, ft_strsplit(tab[ret], ' '), ret);
	}
	free(stock);
	free(tab);
}
