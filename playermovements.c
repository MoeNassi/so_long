/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermovements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:49:40 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/28 12:53:27 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	rightside(t_var *r)
{
	if (r->map[r->p2 / 32][r->p1 / 32 + 1] != '1')
	{
		if (r->map[r->p2 / 32][r->p1 / 32 + 1] == 'C')
		{
			r->count--;
			r->map[r->p2 / 32][r->p1 / 32 + 1] = '0';
			mlx_put_image_to_window(r->mlx, r->mlx_win, r->p,
				r->p1 + 32, r->p2);
		}
		if (r->map[r->p2 / 32][r->p1 / 32 + 1] == 'E' && r->count > 0)
		{
			mlx_put_image_to_window(r->mlx, r->mlx_win, r->p,
				r->p1 + 32, r->p2);
			mlx_put_image_to_window(r->mlx, r->mlx_win, r->door,
				r->p1 + 32, r->p2);
			return ;
		}
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->p, r->p1, r->p2);
		mlx_put_image_to_window(r->mlx, r->mlx_win, r->right,
			r->p1 + 32, r->p2);
		r->p1 += 32;
	}
}

void	leftside(t_var *l)
{
	if (l->map[l->p2 / 32][l->p1 / 32 - 1] != '1')
	{
		if (l->map[l->p2 / 32][l->p1 / 32 - 1] == 'C')
		{
			l->count--;
			l->map[l->p2 / 32][l->p1 / 32 - 1] = '0';
			mlx_put_image_to_window(l->mlx, l->mlx_win, l->p,
				l->p1 - 32, l->p2);
		}
		if (l->map[l->p2 / 32][l->p1 / 32 - 1] == 'E' && l->count > 0)
		{
			mlx_put_image_to_window(l->mlx, l->mlx_win, l->p,
				l->p1 - 32, l->p2);
			mlx_put_image_to_window(l->mlx, l->mlx_win, l->door,
				l->p1 - 32, l->p2);
			return ;
		}
		mlx_put_image_to_window(l->mlx, l->mlx_win, l->p, l->p1, l->p2);
		mlx_put_image_to_window(l->mlx, l->mlx_win, l->left, l->p1 - 32, l->p2);
		l->p1 -= 32;
	}
}

void	upside(t_var *u)
{
	if (u->map[u->p2 / 32 - 1][u->p1 / 32] != '1')
	{
		if (u->map[u->p2 / 32 - 1][u->p1 / 32] == 'C')
		{
			u->count--;
			u->map[u->p2 / 32 - 1][u->p1 / 32] = '0';
			mlx_put_image_to_window(u->mlx, u->mlx_win, u->p,
				u->p1, u->p2 - 32);
		}
		if (u->map[u->p2 / 32 - 1][u->p1 / 32] == 'E' && u->count > 0)
		{
			mlx_put_image_to_window(u->mlx, u->mlx_win, u->p,
				u->p1, u->p2 - 32);
			mlx_put_image_to_window(u->mlx, u->mlx_win,
				u->door, u->p1, u->p2 - 32);
			return ;
		}
		mlx_put_image_to_window(u->mlx, u->mlx_win, u->p, u->p1, u->p2);
		mlx_put_image_to_window(u->mlx, u->mlx_win, u->up, u->p1, u->p2 - 32);
		u->p2 -= 32;
	}
}

void	downside(t_var *d)
{
	if (d->map[d->p2 / 32 + 1][d->p1 / 32] != '1')
	{
		if (d->map[d->p2 / 32 + 1][d->p1 / 32] == 'C')
		{
			d->count--;
			d->map[d->p2 / 32 + 1][d->p1 / 32] = '0';
			mlx_put_image_to_window(d->mlx, d->mlx_win,
				d->p, d->p1, d->p2 + 32);
		}
		if (d->map[d->p2 / 32 + 1][d->p1 / 32] == 'E' && d->count > 0)
		{
			mlx_put_image_to_window(d->mlx, d->mlx_win, d->p,
				d->p1, d->p2 + 32);
			mlx_put_image_to_window(d->mlx, d->mlx_win,
				d->door, d->p1, d->p2 + 32);
			return ;
		}
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->p, d->p1, d->p2);
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->down, d->p1, d->p2 + 32);
		d->p2 += 32;
	}
}
