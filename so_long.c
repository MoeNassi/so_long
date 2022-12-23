/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:23 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/23 11:26:22 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include "libft/libft.h"

void	checkpaths(t_var *pcheck, t_text *seccheck)
{
	int		i;
	int		j;

	i = heiwei(pcheck, 'w');
	j = heiwei(pcheck, 'h');
	pcheck->mlx_win = mlx_new_window(pcheck->mlx, i, j, "mnassi");
	pcheck->ptr = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/wall/minecraft.xpm", &pcheck->x, &pcheck->y);
	pcheck->p = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/wall/blackwall.xpm", &pcheck->x, &pcheck->y);
	pcheck->door = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/door/hornet.xpm", &pcheck->x, &pcheck->y);
	pcheck->player = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/player/player.xpm", &pcheck->x, &pcheck->y);	
	seccheck->player = mlx_xpm_file_to_image(pcheck->mlx, "./pixe//player/player.xpm", &pcheck->x, &pcheck->y);
	seccheck->res = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/collectibles/geo.xpm", &pcheck->x, &pcheck->y);
	pcheck->player1 = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/player/player1.xpm", &pcheck->x, &pcheck->y);
	if (pcheck->ptr == NULL || pcheck->p == NULL || pcheck->door == NULL || pcheck->player == NULL ||
		seccheck->player == NULL || seccheck->res == NULL || pcheck->player1 == NULL)
		ft_error(6);
}

void	checkcompo(t_var *scheck)
{
	static int	P;
	static int	E;
	int			index;
	int			j;

	index = 0;
	j = 0;
	while (scheck->map[index])
	{
		j = 0;
		while (scheck->map[index][j] != '\n' && scheck->map[index][j])
		{
			if (scheck->map[index][j] == 'P')
				P++;
			if (scheck->map[index][j] == 'E')
				E++;
			if (P > 1 || E > 1)
				ft_error(2);
			j++;
		}
		index++;
	}
}

void	checkeverything(t_var *dcheck)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	checkcompo(dcheck);
	while (dcheck->map[i])
	{
		j = 0;
		while (dcheck->map[i][k] != '\n' && dcheck->map[i][k])
			k++;
		while (dcheck->map[i][j] && dcheck->map[i][j] != '\n')
			j++;
		if (k != j)
			ft_error(2);
		i++;
	}
	mapchecker(dcheck);
}

void	rightside(t_var *right)
{
	if (right->map[right->p2 / 32][right->p1 / 32 + 1] != '1')
	{
		if (right->map[right->p2 / 32][right->p1 / 32 + 1] == 'C')
		{
			if (right->count > 0)
				right->count--;
			right->map[right->p2 / 32][right->p1 / 32 + 1] = '0';
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1 + 32, right->p2);
		}
		if (right->map[right->p2 / 32][right->p1 / 32 + 1] == 'E' && right->count > 0)
		{
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->p, right->p1 + 32, right->p2);
			mlx_put_image_to_window(right->mlx, right->mlx_win, right->door, right->p1 + 32, right->p2);
			return ;
		}
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
		{
			if (left->count > 0)
				left->count--;
			left->map[left->p2 / 32][left->p1 / 32 - 1] = '0';
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1 - 32, left->p2);
		}
		if (left->map[left->p2 / 32][left->p1 / 32 - 1] == 'E' && left->count > 0)
		{
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->p, left->p1 - 32, left->p2);
			mlx_put_image_to_window(left->mlx, left->mlx_win, left->door, left->p1 - 32, left->p2);
			return ;
		}
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
		{
			if (up->count > 0)
				up->count--;
			up->map[up->p2 / 32 - 1][up->p1 / 32] = '0';
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2 - 32);
		}
		if (up->map[up->p2 / 32 - 1][up->p1 / 32] == 'E' && up->count > 0)
		{
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->p, up->p1, up->p2 - 32);
			mlx_put_image_to_window(up->mlx, up->mlx_win, up->door, up->p1, up->p2 - 32);
			return ;
		}
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
		{
			if (down->count > 0)
				down->count--;
			down->map[down->p2 / 32 + 1][down->p1 / 32] = '0';
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2 + 32);
		}
		if (down->map[down->p2 / 32 + 1][down->p1 / 32] == 'E' && down->count > 0)
		{
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2 + 32);
			mlx_put_image_to_window(down->mlx, down->mlx_win, down->door, down->p1, down->p2 + 32);
			return ;
		}
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->p, down->p1, down->p2);
		mlx_put_image_to_window(down->mlx, down->mlx_win, down->player, down->p1, down->p2 + 32);
		down->p2 += 32;
	}
}

int		keypress(int keycode, t_var *big)
{
	static int		i;

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
	if (big->map[big->p2 / 32][big->p1 / 32] == 'E' && big->count <= 0)
		ft_error(3);
	ft_putnbr_fd(i, 1);
	i++;
	ft_putstr_fd("\n", 1);
	return (0);
}

int check_left(char **arr, int i, int j)
{
	if (arr[i][j - 1] == '0')
	{
		arr[i][j - 1] = 'P';
		arr[i][j] = '1';
		return (1);
	}
	return (0);
}

int check_right(char **arr, int i, int j)
{
	if (arr[i][j + 1] == '0')
	{
		arr[i][j + 1] = 'P';
		arr[i][j] = '1';
		return (1);
	}
	return (0);
}

int check_top(char **arr, int i, int j)
{
	if (arr[i - 1][j] == '0')
	{
		arr[i - 1][j] = 'P';
		arr[i][j] = '1';
		return (1);
	}
	return (0);
}

int check_bottom(char **arr, int i, int j)
{
	if (arr[i + 1][j] == '0')
	{
		arr[i + 1][j] = 'P';
		arr[i][j] = '1';
		return (1);
	}
	return (0);
}

int ft_test(char **arr, int i, int j)
{
	if (check_left(arr, i, j) || check_right(arr, i, j) || check_bottom(arr, i, j) || check_top(arr, i, j))
	{
		ft_test(arr, i, j);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_var		bigbrother;
	t_text		big;

	bigbrother.count = 0;
	if (ac == 2)
	{
		bigbrother.mlx = mlx_init();
		if (!bigbrother.mlx)
			ft_error(4);
		bigbrother.map = reading(av);
		if (*bigbrother.map == NULL)
			ft_error(2);
		checkeverything(&bigbrother);
		checkpaths(&bigbrother, &big);
		copy(av, &bigbrother, &big);
		if (!ft_test(bigbrother.map, bigbrother.p2 / 32, bigbrother.p1 / 32))
			ft_error(2);
		mlx_hook(bigbrother.mlx_win, 2, 1L<<0, keypress, &bigbrother);
		mlx_loop(bigbrother.mlx);
		mlx_destroy_window(bigbrother.mlx, bigbrother.mlx_win);
	}
	ft_error(1);
}
