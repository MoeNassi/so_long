/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmapp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:13:16 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/18 16:37:34 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

char	**reading(t_var *read, t_text *big)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		fd;
	char	**ptr;

	i = 0;
	y = 0;
	fd = open("map.ber", O_RDONLY);
	ptr = (char **)malloc(33 * sizeof(char *));
	ptr[0] = get_next_line(fd);
	while (ptr[i++])
		ptr[i] = get_next_line(fd);
	ptr[i] = NULL;
	i = -1;
	while (ptr[++i])
	{
		j = 0;
		x = 0;
		while(ptr[i][j])
		{
			if (ptr[i][j] == '1')
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->ptr, x, y);
			else if (ptr[i][j] == '0')
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
			else if (ptr[i][j] == 'E')
			{
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->door, x, y);
			}
			else if (ptr[i][j] == 'P')
			{
				read->p1 = x;
				read->p2 = y;
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->player, x, y);
			}
			else if (ptr[i][j] == 'C')
			{
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->res, x, y);
			}
			x += 32;
			j++;
		}
		y += 32;
	}
	return (ptr);
}
