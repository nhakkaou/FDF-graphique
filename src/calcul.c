/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 03:42:15 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/25 22:44:40 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		num_colon(char *s, char c)
{
	int		count;
	int		i;

	count = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		i++;
	}
	return (count);
}

int		num_ligne(int fd)
{
	int		cp;
	char	*str;

	cp = 0;
	while (get_next_line(fd, &str) != 0)
	{
		free(str);
		cp++;
	}
	return (cp);
}

t_vect	init_v(void)
{
	t_vect	p;

	p.x = 0;
	p.y = 0;
	p.z = 0;
	return (p);
}

void	ft_error(char *msg)
{
	ft_putendl(msg);
	exit(1);
}
