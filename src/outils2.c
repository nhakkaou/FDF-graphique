/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:43:00 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 00:23:35 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	moin_zoom(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (mlx.sym == 2)
			{
				mlx.vect_tb[i][j].x /= mlx.zoom;
				mlx.vect_tb[i][j].y /= mlx.zoom;
			}
			else
			{
				mlx.copie_tb[i][j].x /= mlx.zoom;
				mlx.copie_tb[i][j].y /= mlx.zoom;
			}
			j++;
		}
		i++;
	}
	(mlx.sym == 2) ? draw(mlx) : draw_simple(mlx);
}

void	plus_zoom(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (mlx.sym == 2)
			{
				mlx.vect_tb[i][j].x *= mlx.zoom;
				mlx.vect_tb[i][j].y *= mlx.zoom;
			}
			else
			{
				mlx.copie_tb[i][j].x *= mlx.zoom;
				mlx.copie_tb[i][j].y *= mlx.zoom;
			}
			j++;
		}
		i++;
	}
	(mlx.sym == 2) ? draw(mlx) : draw_simple(mlx);
}

void	plus_hauteur(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			mlx.vect_tb[i][j].z *= 1.1;
			mlx.vect_tb[i][j].y -= mlx.vect_tb[i][j].z;
			j++;
		}
		i++;
	}
	draw(mlx);
}

void	moin_hauteur(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			mlx.vect_tb[i][j].z *= 1.1;
			mlx.vect_tb[i][j].y += mlx.vect_tb[i][j].z;
			j++;
		}
		i++;
	}
	draw(mlx);
}

void	change_color(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			mlx.vect_tb[i][j].color += 6000;
			j++;
		}
		i++;
	}
	draw(mlx);
}
