/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:47:53 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/05 15:28:29 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "so_long_tools/libft.h"

void	ft_countmoves(t_var *first, int i)
{
	char	*count;

	count = ft_itoa(i);
	mlx_put_image_to_window(first->mlx, first->mlx_win, first->ptr, 0, 0);
	mlx_string_put(first->mlx, first->mlx_win, 0, 0, 0x000000, count);
	free(count);
}
