/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:25:58 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/22 17:45:37 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	checkpaths(t_var *move, t_movement *frame)
{
	frame->first = mlx_xpm_file_to_image(move->mlx, "./pixe/monster/0.xpm", &move->x, &move->y);
	frame->second = mlx_xpm_file_to_image(move->mlx, "./pixe/monster/1.xpm", &move->x, &move->y);
	frame->third = mlx_xpm_file_to_image(move->mlx, "./pixe/monster/2.xpm", &move->x, &move->y);
	frame->fourth = mlx_xpm_file_to_image(move->mlx, "./pixe/monster/3.xpm", &move->x, &move->y);
	frame->fifth = mlx_xpm_file_to_image(move->mlx, "./pixe/monster/4.xpm", &move->x, &move->y);
	if (frame->first == NULL || frame->second == NULL || frame->third == NULL || frame->fourth == NULL ||
		frame->fifth == NULL)
		ft_error(6);
}

void	enemy(t_var *move, t_movement *frame)
{
	int		i;
	int		y;
	int		x;
	int		j;

	i = 0;
	y = 0;
	checkpaths(move, frame);
	while (move->map[i])
	{
		j = 0;
		x = 0;
		while (move->map[i][j])
		{
			if (move->map[i][j] == 'A')
				mlx_put_image_to_window(move->mlx, move->mlx, frame->first, x, y);
			j++;
			x += 32;
		}
		y += 32;
		i++;
	}
}