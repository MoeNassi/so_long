/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:23 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/18 17:26:19 by mnassi           ###   ########.fr       */
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
		mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1, right->p2);
		mlx_put_image_to_window(right->mlx, right->mlx_win, right->player, right->p1 + 32, right->p2);
		right->p1 += 32;
	}
}

void	leftside(t_var *left)
{
	if (left->map[left->p2 / 32][left->p1 / 32 - 1] != '1')
	{
		mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1, left->p2);
		mlx_put_image_to_window(left->mlx, left->mlx_win, left->player1, left->p1 - 32, left->p2);
		left->p1 -= 32;
	}
}

void	upside(t_var *up)
{
	if (up->map[up->p2 / 32][up->p1 / 32] == 'E')
		exit(0);
	if (up->map[up->p2 / 32 - 1][up->p1 / 32] != '1')
	{
		mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2);
		mlx_put_image_to_window(up->mlx, up->mlx_win, up->player, up->p1, up->p2 - 32);
		up->p2 -= 32;
	}
}

void	downside(t_var *down)
{
	if (down->map[down->p2 / 32 + 1][down->p1 / 32] != '1')
	{
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2);
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->player, down->p1, down->p2 + 32);
		down->p2 += 32;
	}
}

int		keypress(int keycode, t_var *big)
{
	int		i;

	i = 0;
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
	ft_putnbr_fd(keycode, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}


int	main(void)
{
	t_var		bigbrother;
	t_text		big;

	bigbrother.mlx = mlx_init();
	bigbrother.mlx_win = mlx_new_window(bigbrother.mlx, 896, 224, "mnassi");
	bigbrother.ptr = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/blackwall.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.p = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/1.xpm", &bigbrother.x, &bigbrother.y);
	big.door = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/door.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.player = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player.xpm", &bigbrother.x, &bigbrother.y);	big.player = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player.xpm", &bigbrother.x, &bigbrother.y);
	big.res = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/geo.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.player1 = mlx_xpm_file_to_image(bigbrother.mlx, "./pixe/player1.xpm", &bigbrother.x, &bigbrother.y);
	bigbrother.map = reading(&bigbrother, &big);
	mlx_hook(bigbrother.mlx_win, 2, 1L<<0, keypress, &bigbrother);
	mlx_loop(bigbrother.mlx);
	mlx_destroy_window(bigbrother.mlx, bigbrother.mlx_win);
	free(bigbrother.mlx);
}
