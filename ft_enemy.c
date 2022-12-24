/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:56:19 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/24 18:51:31 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int		moveenemy(int key, t_var *move)
{
	key = rand() % 9;
	printf("%s", "hello");
	return(0);
	if (key == 0)
	{
		mlx_put_image_to_window(move->mlx, move->mlx_win, move->p, move->ene2, move->ene1);
		mlx_put_image_to_window(move->mlx, move->mlx_win, move->secondcount, move->ene2, move->ene1 + 32);
	}
	if (key == 1)
	{
		mlx_put_image_to_window(move->mlx, move->mlx_win, move->p, move->ene2, move->ene1);
		mlx_put_image_to_window(move->mlx, move->mlx_win, move->secondcount, move->ene2, move->ene1 - 32);
	}
	return (0);
}

void	enemy(t_var *first, int x, int y, int i, int j)
{
	if (first->map[i][j] == 'A')
	{
		first->ene1 = y;
		first->ene2 = x;
		mlx_put_image_to_window(first->mlx, first->mlx_win, first->p, x, y);
		mlx_put_image_to_window(first->mlx, first->mlx_win, first->secondcount, x, y);
		mlx_loop_hook(first->mlx, moveenemy, first);
	}
}
