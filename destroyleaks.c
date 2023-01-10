/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyleaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:24:15 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/10 10:42:33 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	destroyleaks(t_var *remo, t_text *rem)
{
	mlx_destroy_image(remo->mlx, remo->p);
	mlx_destroy_image(remo->mlx, remo->ptr);
	mlx_destroy_image(remo->mlx, remo->up);
	mlx_destroy_image(remo->mlx, remo->right);
	mlx_destroy_image(remo->mlx, remo->down);
	mlx_destroy_image(remo->mlx, remo->left);
	mlx_destroy_image(remo->mlx, remo->door);
	mlx_destroy_image(remo->mlx, rem->player);
	mlx_destroy_image(remo->mlx, rem->res);
	mlx_destroy_image(remo->mlx, remo->secdoor);
	mlx_destroy_window(remo->mlx, remo->mlx_win);
}
