/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:42:00 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/16 17:22:12 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"

char	*play(char **blocks)
{
	int		i;
	int		y;
	int		fd;

	i = 0;
	y = 0;
	fd = open("map1.ber", O_RDONLY);
	blocks[0] = get_next_line(fd);
	while (blocks[i++])
		blocks[i] = get_next_line(fd);
	return (*blocks);
}
