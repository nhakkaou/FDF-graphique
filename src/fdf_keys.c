/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:58:54 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 00:22:58 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(t_lx *mlx)
{
	if (mlx->sym == 1)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		draw(*mlx);
		mlx->sym = 2;
	}
	else
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		draw(*mlx);
	}
}

static void	trance(int key, t_lx *mlx)
{
	if (key == 123)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		trans_gauche(*mlx);
	}
	else if (key == 124)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		trans_droite(*mlx);
	}
	else if (key == 126)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		trans_up(*mlx);
	}
	else if (key == 125)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		trans_down(*mlx);
	}
}

static void	hauteur(int key, t_lx *mlx)
{
	if (key == 13)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		plus_hauteur(*mlx);
	}
	else if (key == 14)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		moin_hauteur(*mlx);
	}
}

static void	zoom(int key, t_lx *mlx)
{
	if (key == 84)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		moin_zoom(*mlx);
	}
	else if (key == 91)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		plus_zoom(*mlx);
	}
}

int			fdf_keys(int key, t_lx *mlx)
{
	if (key == 53)
	{
		free(mlx->copie_tb);
		free(mlx->vect_tb);
		exit(0);
	}
	else if (key == 69)
		iso(mlx);
	else if (key == 49)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		change_color(*mlx);
	}
	else if (key == 82)
	{
		mlx_clear_window(mlx->ptr, mlx->window);
		draw_simple(*mlx);
		mlx->sym = 1;
	}
	hauteur(key, mlx);
	zoom(key, mlx);
	trance(key, mlx);
	return (0);
}
