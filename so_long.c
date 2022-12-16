/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:23 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/16 19:32:25 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include "libft/libft.h"

int		keypress(int keycode, t_var *big)
{
	printf("hello\n");
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
	{
		// if (big->map[big->p1 + 1][big->p2] == '0')
		// {
			mlx_put_image_to_window(big->mlx, big->mlx_win, big->p, big->p1, big->p2);
			mlx_put_image_to_window(big->mlx, big->mlx_win, big->player, big->p1 + 32, big->p2);
			big->p1 += 32;
		// }
	}
		//reading1(big, &temp);
	ft_putnbr_fd(keycode, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	main(void)
{
	t_var		bigbrother;
	t_text		big;

	bigbrother.mlx = mlx_init();
	bigbrother.mlx_win = mlx_new_window(bigbrother.mlx, 480, 160, "mnassi");
	bigbrother.ptr = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/blackwall.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.p = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/1.xpm", &bigbrother.x, &bigbrother.y);
	big.door = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/door.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.player = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player.xpm", &bigbrother.x, &bigbrother.y);
	big.player = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player.xpm", &bigbrother.x, &bigbrother.y);
	big.res = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/geo.xpm", &bigbrother.x, &bigbrother.y);
	
	bigbrother.map = reading(&bigbrother, &big);

	
	mlx_hook(bigbrother.mlx_win, 2, 1L<<0, keypress, &bigbrother);
	mlx_loop(bigbrother.mlx);
	mlx_destroy_window(bigbrother.mlx, bigbrother.mlx_win);
	free(bigbrother.mlx);
}
