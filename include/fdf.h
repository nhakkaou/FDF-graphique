/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:17:40 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 00:12:36 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_vect;

typedef struct	s_lx
{
	int		sym;
	int		nc;
	int		nl;
	t_vect	**vect_tb;
	t_vect	**copie_tb;
	void	*ptr;
	void	*window;
	int		color;
	int		zoom;
}				t_lx;

typedef struct	s_line
{
	int	dx;
	int	dy;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;
	int	i;
}				t_line;

typedef struct	s_readv
{
	char	*line;
	int		i;
	int		j;
	int		n;
}				t_readv;

void			change_i(t_lx *mlx);
void			draw(t_lx mlx);
int				fdf_read(int fd, t_lx *mlx);
void			ft_error();
t_vect			init_v();
int				num_colon(char *s, char c);
int				num_ligne(int fd);
void			ligne(t_vect p1, t_vect p2, t_lx mlx);
void			trans_droite(t_lx mlx);
void			trans_up(t_lx mlx);
void			trans_down(t_lx mlx);
void			trans_gauche(t_lx mlx);
void			plus_zoom(t_lx mlx);
void			moin_zoom(t_lx mlx);
void			plus_hauteur(t_lx mlx);
void			moin_hauteur(t_lx mlx);
void			change_color(t_lx mlx);
void			rempli(t_lx *mlx);
void			draw_simple(t_lx mlx);
int				count_lines(t_lx *mlx, char *argv);
int				count_values(char *line);
void			get_values(t_readv r, char **t, t_lx *mlx);
int				fdf_keys(int key, t_lx *mlx);
int				nb_colon(int fd);
void			error_file(void);
void			error_usage(void);

#endif
