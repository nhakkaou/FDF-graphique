/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:10:13 by nhakkaou          #+#    #+#             */
/*   Updated: 2018/10/16 20:36:52 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbch(int n)
{
	int i;

	i = (n < 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
