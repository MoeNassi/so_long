/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spriteanim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:03 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/10 10:42:58 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	ft_animation(t_var *anime)
{
	if (anime->count == 0)
	{
		mlx_put_image_to_window(anime->mlx, anime->mlx_win, anime->p,
			anime->doorp2, anime->doorp1);
		mlx_put_image_to_window(anime->mlx, anime->mlx_win, anime->secdoor,
			anime->doorp2, anime->doorp1);
	}
}
