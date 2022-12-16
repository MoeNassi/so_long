/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:59:03 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/16 14:17:07 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	move(t_text *sec, t_var *move)
{
	int		y;
	int		x;
	char	*blocks[34];

	y = 0;
	x = 0;
	play(blocks);
	reading1(move, sec);
}