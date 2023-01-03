/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heiwei.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:48:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/28 11:52:42 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	weight(t_var *he)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (he->map[x])
	{
		while (he->map[x][y] != '\n' && he->map[x][y])
			y++;
		if (he->map[x][y - 1] != '1')
			ft_error(2);
		x++;
	}
	return (x * 32);
}

int	height(t_var *count)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (count->map[0][y] != '\n' && count->map[0][y])
	{
		if (count->map[0][y] != '1')
			ft_error(2);
		y++;
	}
	return (y * 32);
}
