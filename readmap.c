/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:10:31 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/16 19:11:57 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"

void	reading1(t_var *read, t_text *big)
{
	int			i;
	int			j;
	int			y;
	int			x;
	char		*blocks[34];

	i = -1;
	y = 0;
	mlx_clear_window(read->mlx, read->mlx_win);
	play(blocks);
	while (blocks[++i])
	{
		j = 0;
		x = 0;
		while(blocks[i][j])
		{
			if (blocks[i][j] && blocks[i][j] == '1')
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->ptr, x, y);
			else if (blocks[i][j] && blocks[i][j] == '0')
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
			else if (blocks[i][j] && blocks[i][j] == 'E')
			{
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->door, x, y);
			}
			else if (blocks[i][j] == 'P')
			{
				if (blocks[i+1][j] == 0)
				{	
					blocks[i+1][j] = 'P';
					mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				}
			}
			else if (blocks[i][j] && blocks[i][j] == 'C')
			{
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->res, x, y);
			}
			x += 32;
			j++;
		}
		y += 32;
	}
}
