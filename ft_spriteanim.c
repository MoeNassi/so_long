/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spriteanim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:03 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/26 17:38:27 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	ft_animation(t_var *animsp)
{
	if (animsp->count == 0)
	{
		mlx_put_image_to_window(animsp->mlx, animsp->mlx_win, animsp->p,
			animsp->doorp2, animsp->doorp1);
		mlx_put_image_to_window(animsp->mlx, animsp->mlx_win, animsp->secdoor,
			animsp->doorp2, animsp->doorp1);
	}
}
