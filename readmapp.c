/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmapp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:13:16 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/27 11:17:53 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

char	**reading(char **av)
{
	int		fd;
	char	**ptr;
	char	*line;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(2);
	ptr = (char **)malloc(33 * sizeof(char *));
	if (!ptr)
		ft_error(1);
	line = get_next_line(fd);
	while (line)
	{
		if (i > 33)
			ft_error(2);
		ptr[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	ptr[i] = NULL;
	close(fd);
	return (ptr);
}

void	receiver(char c, int x, int y, t_var *r)
{
	if (c == '1')
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->ptr, x, y);
	else if (c == '0')
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->p, x, y);
	else if (c == 'E')
	{
		r->doorp1 = y;
		r->doorp2 = x;
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->p, x, y);
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->door, x, y);
	}
	else if (c == 'P')
	{
		r->p1 = x;
		r->p2 = y;
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->p, x, y);
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->right, x, y);
	}
}

void	copy(t_var *r, t_text *big)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (r->map[++i])
	{
		j = 0;
		x = 0;
		while (r->map[i][j] && r->map[i][j] != '\n')
		{
			receiver(r->map[i][j], x, y, r);
			if (r->map[i][j] == 'C')
			{
				r->count++;
				mlx_put_image_to_window(r->mlx, r->mlx_win, r->p, x, y);
				mlx_put_image_to_window(r->mlx, r->mlx_win, big->res, x, y);
			}
			x += 32;
			j++;
		}
		y += 32;
	}
}
