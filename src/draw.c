/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 00:22:33 by nhakkaou          #+#    #+#             */
/*   Updated: 2019/01/26 00:22:37 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (i != mlx.nl - 1)
				ligne(mlx.vect_tb[i][j], mlx.vect_tb[i + 1][j], mlx);
			if (j != mlx.nc - 1)
				ligne(mlx.vect_tb[i][j], mlx.vect_tb[i][j + 1], mlx);
			j++;
		}
		i++;
	}
}

void	change_i(t_lx *mlx)
{
	int		i;
	int		j;
	int		prev_x;
	int		prev_y;

	i = 0;
	if (mlx->sym == 1)
	{
		while (i < mlx->nl)
		{
			j = 0;
			while (j < mlx->nc)
			{
				prev_x = mlx->vect_tb[i][j].x;
				prev_y = mlx->vect_tb[i][j].y;
				mlx->vect_tb[i][j].x = (prev_x - prev_y) * cos(0.523599);
				mlx->vect_tb[i][j].y = -mlx->vect_tb[i][j].z + \
					(prev_x + prev_y) * sin(0.523599);
				j++;
			}
			i++;
		}
		mlx->sym = 2;
		draw(*mlx);
	}
}

void	draw_simple(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (i != mlx.nl - 1)
				ligne(mlx.copie_tb[i][j], mlx.copie_tb[i + 1][j], mlx);
			if (j != mlx.nc - 1)
				ligne(mlx.copie_tb[i][j], mlx.copie_tb[i][j + 1], mlx);
			j++;
		}
		i++;
	}
}

void	get_values(t_readv r, char **t, t_lx *mlx)
{
	r.i = 0;
	while (t[r.i])
	{
		mlx->vect_tb[r.j][r.i].z = ft_atoi(t[r.i]);
		mlx->vect_tb[r.j][r.i].y = r.j * 12;
		mlx->vect_tb[r.j][r.i].x = r.i * 12;
		mlx->vect_tb[r.j][r.i].color = 0xFFFFFF - 65535 - \
			(mlx->vect_tb[r.j][r.i].z);
		r.i++;
	}
	free(t);
}
