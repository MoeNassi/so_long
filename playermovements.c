/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermovements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:49:40 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/26 17:36:20 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	rightside(t_var *right)
{
	if (right->map[right->p2 / 32][right->p1 / 32 + 1] != '1')
	{
		if (right->map[right->p2 / 32][right->p1 / 32 + 1] == 'C')
		{
			if (right->count > 0)
				right->count--;
			right->map[right->p2 / 32][right->p1 / 32 + 1] = '0';
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1 + 32, right->p2);
		}
		if (right->map[right->p2 / 32][right->p1 / 32 + 1] == 'E' && right->count > 0)
		{
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1 + 32, right->p2);
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->door, right->p1 + 32, right->p2);
			return ;
		}
		mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1, right->p2);
		mlx_put_image_to_window(right->mlx, right->mlx_win, right->right, right->p1 + 32, right->p2);
		right->p1 += 32;
		
	}
}

void	leftside(t_var *left)
{
	if (left->map[left->p2 / 32][left->p1 / 32 - 1] != '1')
	{
		if (left->map[left->p2 / 32][left->p1 / 32 - 1] == 'C')
		{
			if (left->count > 0)
				left->count--;
			left->map[left->p2 / 32][left->p1 / 32 - 1] = '0';
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1 - 32, left->p2);
		}
		if (left->map[left->p2 / 32][left->p1 / 32 - 1] == 'E' && left->count > 0)
		{
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1 - 32, left->p2);
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->door, left->p1 - 32, left->p2);
			return ;
		}
		mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1, left->p2);
		mlx_put_image_to_window(left->mlx, left->mlx_win, left->left, left->p1 - 32, left->p2);
		left->p1 -= 32;
	}
}

void	upside(t_var *up)
{
	if (up->map[up->p2 / 32 - 1][up->p1 / 32] != '1')
	{
		if (up->map[up->p2 / 32 - 1][up->p1 / 32] == 'C')
		{
			if (up->count > 0)
				up->count--;
			up->map[up->p2 / 32 - 1][up->p1 / 32] = '0';
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2 - 32);
		}
		if (up->map[up->p2 / 32 - 1][up->p1 / 32] == 'E' && up->count > 0)
		{
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2 - 32);
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->door, up->p1, up->p2 - 32);
			return ;
		}
		mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2);
		mlx_put_image_to_window(up->mlx, up->mlx_win, up->up, up->p1, up->p2 - 32);
		up->p2 -= 32;
	}
}

void	downside(t_var *down)
{
	if (down->map[down->p2 / 32 + 1][down->p1 / 32] != '1')
	{
		if (down->map[down->p2 / 32 + 1][down->p1 / 32] == 'C')
		{
			if (down->count > 0)
				down->count--;
			down->map[down->p2 / 32 + 1][down->p1 / 32] = '0';
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2 + 32);
		}
		if (down->map[down->p2 / 32 + 1][down->p1 / 32] == 'E' && down->count > 0)
		{
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2 + 32);
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->door, down->p1, down->p2 + 32);
			return ;
		}
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2);
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->down, down->p1, down->p2 + 32);
		down->p2 += 32;
	}
}
