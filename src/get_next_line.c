/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:46:51 by nhakkaou          #+#    #+#             */
/*   Updated: 2019/01/25 23:03:38 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_aloline(char **str, int fd)
{
	int	r;

	r = 0;
	while (str[fd][r] != '\n' && str[fd][r] != '\0')
		r++;
	return (r);
}

int	get_next_line(int fd, char **line)
{
	static char *str[256];
	char		buffer[BUFF_SIZE + 1];
	int			re;
	int			i;

	if (fd < 0 || read(fd, buffer, 0) || !line)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((re = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[re] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	i = ft_aloline(str, fd);
	*line = ft_strnew(i);
	*line = ft_strsub(str[fd], 0, i);
	if (!re && !ft_strlen(str[fd]) && !i)
		return (0);
	str[fd] = ft_strdup(str[fd] + i + 1);
	return (1);
}
