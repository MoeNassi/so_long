/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyleaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:24:15 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/26 16:41:09 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	destroyleaks(t_var *remove, t_text *rem)
{
	mlx_destroy_image(remove->mlx, remove->p);
	mlx_destroy_image(remove->mlx, remove->ptr);
	mlx_destroy_image(remove->mlx, remove->up);
	mlx_destroy_image(remove->mlx, remove->right);
	mlx_destroy_image(remove->mlx, remove->down);
	mlx_destroy_image(remove->mlx, remove->left);
	mlx_destroy_image(remove->mlx, remove->door);
	mlx_destroy_image(remove->mlx, rem->player);
	mlx_destroy_image(remove->mlx, rem->res);
	mlx_destroy_image(remove->mlx, remove->secdoor);
	mlx_destroy_window(remove->mlx, remove->mlx_win);
}
