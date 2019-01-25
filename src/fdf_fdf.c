/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 00:23:50 by nhakkaou          #+#    #+#             */
/*   Updated: 2019/01/26 00:23:55 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ligne1(t_line l, t_vect p1, t_lx mlx)
{
	l.cumul = l.dx / 2;
	l.i = 1;
	while (l.i++ <= l.dx)
	{
		l.x += l.xinc;
		l.cumul += l.dy;
		if (l.cumul >= l.dx)
		{
			l.cumul -= l.dx;
			l.y += l.yinc;
		}
		mlx_pixel_put(mlx.ptr, mlx.window, l.x, l.y, p1.color);
	}
}

void	ligne2(t_line l, t_vect p1, t_lx mlx)
{
	l.cumul = l.dy / 2;
	l.i = 1;
	while (l.i++ <= l.dy)
	{
		l.y += l.yinc;
		l.cumul += l.dx;
		if (l.cumul >= l.dy)
		{
			l.cumul -= l.dy;
			l.x += l.xinc;
		}
		mlx_pixel_put(mlx.ptr, mlx.window, l.x, l.y, p1.color);
	}
}

void	ligne(t_vect p1, t_vect p2, t_lx mlx)
{
	t_line l;

	l.x = p1.x + 500;
	l.y = p1.y + 500;
	l.dx = p2.x - p1.x;
	l.dy = p2.y - p1.y;
	(p1.z <= p2.z) ? p1.color = p2.color : 1 == 1;
	l.xinc = (l.dx > 0) ? 1 : -1;
	l.yinc = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	mlx_pixel_put(mlx.ptr, mlx.window, l.x, l.y, p1.color);
	if (l.dx > l.dy)
		ligne1(l, p1, mlx);
	else
		ligne2(l, p1, mlx);
}

void	rempli(t_lx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->nl)
	{
		j = 0;
		while (j < mlx->nc)
		{
			mlx->copie_tb[i][j].x = mlx->vect_tb[i][j].x;
			mlx->copie_tb[i][j].y = mlx->vect_tb[i][j].y;
			mlx->copie_tb[i][j].z = mlx->vect_tb[i][j].z;
			mlx->copie_tb[i][j].color = mlx->vect_tb[i][j].color;
			j++;
		}
		i++;
	}
}

int		fdf_read(int fd, t_lx *mlx)
{
	t_readv	r;
	char	**t;

	r.j = 0;
	r.i = 0;
	mlx->vect_tb = malloc(sizeof(t_vect *) * mlx->nl);
	mlx->copie_tb = malloc(sizeof(t_vect *) * mlx->nl);
	while (get_next_line(fd, &r.line) && r.j != mlx->nl)
	{
		t = ft_strsplit(r.line, 32);
		free(r.line);
		r.n = 0;
		while (t[r.n])
			r.n++;
		(mlx->nc != r.n) ? error_file() : 1 == 1;
		mlx->vect_tb[r.j] = malloc(sizeof(t_vect) * r.n);
		mlx->copie_tb[r.j] = malloc(sizeof(t_vect) * r.n);
		get_values(r, t, mlx);
		r.j++;
	}
	rempli(mlx);
	change_i(mlx);
	return (0);
}
