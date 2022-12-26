/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:23 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/26 19:00:17 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include "libft/libft.h"

int	destroywin(int key, t_var *dest)
{
	(void) key;
	ft_putstr_fd("Turned off\n", 1);
	exit(0);
	mlx_destroy_window(dest->mlx, dest->mlx_win);
}

int	keypress(int keycode, t_var *big)
{
	upmove(big, keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
		rightside(big);
	if (keycode == 0)
		leftside(big);
	if (keycode == 13)
		upside(big);
	if (keycode == 1)
		downside(big);
	if (big->map[big->p2 / 32][big->p1 / 32] == 'E' && big->count == 0)
		ft_error(3);
	ft_animation(big);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	bigbrother;
	t_text	big;

	bigbrother.count = 0;
	if (ac == 2)
	{
		bigbrother.mlx = mlx_init();
		if (!bigbrother.mlx)
			ft_error(4);
		bigbrother.map = reading(av);
		if (*bigbrother.map == NULL)
			ft_error(2);
		bigbrother.arr = reading(av);
		checkeverything(&bigbrother);
		checkpaths(&bigbrother, &big);
		copy(&bigbrother, &big);
		if (!ft_back(bigbrother.arr, bigbrother.p2 / 32, bigbrother.p1 / 32))
			ft_error(6);
		mlx_hook(bigbrother.mlx_win, 17, 1L << 0, destroywin, &bigbrother);
		mlx_hook(bigbrother.mlx_win, 2, 1L << 0, keypress, &bigbrother);
		mlx_loop(bigbrother.mlx);
		destroyleaks(&bigbrother, &big);
	}
	ft_error(1);
}
