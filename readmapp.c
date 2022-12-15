/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmapp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:13:16 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/15 14:36:18 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "so_long.h"

void	reading(t_var *read)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*blocks[34];
	int		fd;

	i = 0;
	y = 0;
	fd = open("map", O_RDONLY);
	blocks[0] = get_next_line(fd);
	while (blocks[i++])
		blocks[i] = get_next_line(fd);
	i = -1;
	while (blocks[++i])
	{
		j = 0;
		x = 0;
		while(blocks[i][j])
		{
			if (blocks[i][j] && blocks[i][j] == '1')
			{
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->ptr, x, y);
				x += 32;
			}
			else if (blocks[i][j] && blocks[i][j] == '0')
			{
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				x += 32;
			}
			j++;
		}
		y += 32;
	}
}