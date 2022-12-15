/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:23 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/15 14:38:28 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"

int	main(void)
{
	t_var		bigbrother;

	bigbrother.mlx = mlx_init();
	bigbrother.mlx_win = mlx_new_window(bigbrother.mlx, 1056, 1080, "mnassi");
	bigbrother.ptr = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/wall.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.p = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/blue.xpm", &bigbrother.x, &bigbrother.y);
	reading(&bigbrother);
	mlx_loop(bigbrother.mlx);
	mlx_destroy_window(bigbrother.mlx, bigbrother.mlx_win);
	free(bigbrother.mlx);
}
