/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heiwei.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:48:43 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/20 18:18:50 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		heiwei(t_var *count, char declare)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	if (declare == 'w')
	{
		while (count->map[0][y] != '\n' && count->map[0][y])
		{
			if (count->map[0][y] != '1')
				ft_error(2);
			y++;
		}
		// while (count->map[x][y])
		// {
		// 	if (count->map[x][y] != '1')
		// 		ft_error(2);
		// 	x++;
		// }
		return (y * 32);
	}
	if (declare == 'h')
	{
		while (count->map[x])
		{
			while (count->map[x][y] != '\n' && count->map[x][y])
				y++;
			x++;
		}
		return (x * 32);
	}
	return (0);
}