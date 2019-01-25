/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:51:14 by nhakkaou          #+#    #+#             */
/*   Updated: 2019/01/26 00:22:47 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nb_colon(int fd)
{
	int		i;
	char	**t;
	char	*line;

	i = 0;
	get_next_line(fd, &line);
	t = ft_strsplit(line, ' ');
	while (t[i])
		i++;
	free(line);
	free(t);
	return (i);
}

void	error_file(void)
{
	ft_putstr("Error File\n");
	exit(0);
}

void	error_usage(void)
{
	ft_putstr("Usage : ./fdf <filename>\n");
	exit(0);
}
