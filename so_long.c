/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:23 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/21 11:46:50 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include "libft/libft.h"

void	rightside(t_var *right)
{
	if (right->map[right->p2 / 32][right->p1 / 32 + 1] != '1')
	{
		if (right->map[right->p2 / 32][right->p1 / 32 + 1] == 'C')
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1 + 32, right->p2);
		mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1, right->p2);
		mlx_put_image_to_window(right->mlx, right->mlx_win, right->player, right->p1 + 32, right->p2);
		right->p1 += 32;
	}
}

void	leftside(t_var *left)
{
	if (left->map[left->p2 / 32][left->p1 / 32 - 1] != '1')
	{
		if (left->map[left->p2 / 32][left->p1 / 32 - 1] == 'C')
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1 - 32, left->p2);
		mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1, left->p2);
		mlx_put_image_to_window(left->mlx, left->mlx_win, left->player1, left->p1 - 32, left->p2);
		left->p1 -= 32;
	}
}

void	upside(t_var *up)
{
	if (up->map[up->p2 / 32 - 1][up->p1 / 32] != '1')
	{
		if (up->map[up->p2 / 32 - 1][up->p1 / 32] == 'C')
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2 - 32);
		mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2);
		mlx_put_image_to_window(up->mlx, up->mlx_win, up->player, up->p1, up->p2 - 32);
		up->p2 -= 32;
	}
}

void	downside(t_var *down)
{
	if (down->map[down->p2 / 32 + 1][down->p1 / 32] != '1')
	{
		if (down->map[down->p2 / 32 + 1][down->p1 / 32] == 'C')
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2 + 32);
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2);
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->player, down->p1, down->p2 + 32);
		down->p2 += 32;
	}
}

int		keypress(int keycode, t_var *big)
{
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
	if (big->map[big->p2 / 32][big->p1 / 32] == 'E')
			ft_error(3);
	ft_putnbr_fd(keycode, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}


int	main(int ac, char **av)
{
	t_var		bigbrother;
	t_text		big;

	if (ac == 2)
	{
		bigbrother.mlx = mlx_init();
		if (!bigbrother.mlx)
			ft_error(4);
		bigbrother.map = reading(av);
		if (*bigbrother.map == NULL)
			ft_error(2);
		int i = heiwei(&bigbrother, 'w');
		int j = heiwei(&bigbrother, 'h');
		bigbrother.mlx_win = mlx_new_window(bigbrother.mlx, i, j, "mnassi");
		bigbrother.ptr = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/wall/minecraft.xpm", &bigbrother.x, &bigbrother.y);
		bigbrother.p = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/wall/blackwall.xpm", &bigbrother.x, &bigbrother.y);
		big.door = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/door/hornet.xpm", &bigbrother.x, &bigbrother.y);
		bigbrother.player = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player/player.xpm", &bigbrother.x, &bigbrother.y);	
		big.player = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe//player/player.xpm", &bigbrother.x, &bigbrother.y);
		big.res = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/collectibles/geo.xpm", &bigbrother.x, &bigbrother.y);
		bigbrother.player1 = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player/player1.xpm", &bigbrother.x, &bigbrother.y);
		if (bigbrother.ptr == NULL || bigbrother.p == NULL || big.door == NULL || bigbrother.player == NULL ||
			big.player == NULL || big.res == NULL || bigbrother.player1 == NULL)
			ft_error(6);
		copy(av, &bigbrother, &big);
		mlx_hook(bigbrother.mlx_win, 2, 1L<<0, keypress, &bigbrother);
		mlx_loop(bigbrother.mlx);
	}
	ft_error(1);
}
