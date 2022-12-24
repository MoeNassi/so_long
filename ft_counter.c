/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:47:53 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/24 12:30:46 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "libft/libft.h"

void	ft_countmoves(t_var *first, int	i)
{
	mlx_put_image_to_window(first->mlx, first->mlx_win, first->ptr, 0, 0);
	mlx_string_put(first->mlx, first->mlx_win, 0, 0, 0x000000, ft_itoa(i));
}