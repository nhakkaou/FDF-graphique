/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 00:23:09 by nhakkaou          #+#    #+#             */
/*   Updated: 2019/01/26 00:23:13 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_lx	mlx;
	int		fd;
	int		fd1;
	int		f;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		error_usage();
	fd1 = open(av[1], O_RDONLY);
	f = open(av[1], O_RDONLY);
	mlx.nl = num_ligne(fd1);
	mlx.nc = nb_colon(f);
	mlx.zoom = 4;
	mlx.ptr = mlx_init();
	mlx.sym = 1;
	mlx.window = mlx_new_window(mlx.ptr, 2500, 2500, "fdf");
	(ac == 2) ? fdf_read(fd, &mlx) : error_usage();
	mlx_hook(mlx.window, 2, 1, fdf_keys, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
