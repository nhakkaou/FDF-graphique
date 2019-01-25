/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 00:23:26 by nhakkaou          #+#    #+#             */
/*   Updated: 2019/01/26 00:23:27 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_gauche(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx_string_put(mlx.ptr, mlx.window, 50, 50, 0xFFFFFF, "Zoom : 8 / 2");
	mlx_string_put(mlx.ptr, mlx.window, 250, 50, 0xFFFFFF, "Hauteur W / E");
	mlx_string_put(mlx.ptr, mlx.window, 450, 50, 0xFFFFFF, "Isometrique + / 0");
	mlx_string_put(mlx.ptr, mlx.window, 750, 50, 0xFFFFFF, "Change");
	mlx_string_put(mlx.ptr, mlx.window, 850, 50, 0xFFFFFF, "color : Space");
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (mlx.sym == 2)
			{
				mlx.vect_tb[i][j].x -= 10;
			}
			else
				mlx.copie_tb[i][j].x -= 10;
			j++;
		}
		i++;
	}
	(mlx.sym == 2) ? draw(mlx) : draw_simple(mlx);
}

void	trans_droite(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx_string_put(mlx.ptr, mlx.window, 50, 50, 0xFFFFFF, "Zoom : 8 / 2");
	mlx_string_put(mlx.ptr, mlx.window, 250, 50, 0xFFFFFF, "Hauteur W / E");
	mlx_string_put(mlx.ptr, mlx.window, 450, 50, 0xFFFFFF, "Isometrique + / 0");
	mlx_string_put(mlx.ptr, mlx.window, 750, 50, 0xFFFFFF, "Change");
	mlx_string_put(mlx.ptr, mlx.window, 850, 50, 0xFFFFFF, "color : Space");
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (mlx.sym == 2)
			{
				mlx.vect_tb[i][j].x += 10;
			}
			else
				mlx.copie_tb[i][j].x += 10;
			j++;
		}
		i++;
	}
	(mlx.sym == 2) ? draw(mlx) : draw_simple(mlx);
}

void	trans_up(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx_string_put(mlx.ptr, mlx.window, 50, 50, 0xFFFFFF, "Zoom : 8 / 2");
	mlx_string_put(mlx.ptr, mlx.window, 250, 50, 0xFFFFFF, "Hauteur W / E");
	mlx_string_put(mlx.ptr, mlx.window, 450, 50, 0xFFFFFF, "Isometrique + / 0");
	mlx_string_put(mlx.ptr, mlx.window, 750, 50, 0xFFFFFF, "Change");
	mlx_string_put(mlx.ptr, mlx.window, 850, 50, 0xFFFFFF, "color : Space");
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (mlx.sym == 2)
			{
				mlx.vect_tb[i][j].y -= 10;
			}
			else
				mlx.copie_tb[i][j].y -= 10;
			j++;
		}
		i++;
	}
	(mlx.sym == 2) ? draw(mlx) : draw_simple(mlx);
}

void	trans_down(t_lx mlx)
{
	int		i;
	int		j;

	i = 0;
	mlx_string_put(mlx.ptr, mlx.window, 50, 50, 0xFFFFFF, "Zoom : 8 / 2");
	mlx_string_put(mlx.ptr, mlx.window, 250, 50, 0xFFFFFF, "Hauteur W / E");
	mlx_string_put(mlx.ptr, mlx.window, 450, 50, 0xFFFFFF, "Isometrique + / 0");
	mlx_string_put(mlx.ptr, mlx.window, 750, 50, 0xFFFFFF, "Change");
	mlx_string_put(mlx.ptr, mlx.window, 850, 50, 0xFFFFFF, "color : Space");
	while (i < mlx.nl)
	{
		j = 0;
		while (j < mlx.nc)
		{
			if (mlx.sym == 2)
			{
				mlx.vect_tb[i][j].y += 10;
			}
			else
				mlx.copie_tb[i][j].y += 10;
			j++;
		}
		i++;
	}
	(mlx.sym == 2) ? draw(mlx) : draw_simple(mlx);
}
