/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:09:28 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/28 12:45:24 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	checkcompo(t_var *scheck)
{
	static int	p;
	static int	e;
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
				p++;
			if (scheck->map[index][j] == 'E')
				e++;
			if (p > 1 || e > 1)
				ft_error(2);
			j++;
		}
		index++;
	}
	if (p == 0 || e == 0)
		ft_error(2);
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

void	checkpaths(t_var *pcheck, t_text *seccheck)
{
	int		i;
	int		j;

	i = height(pcheck);
	j = weight(pcheck);
	pcheck->mlx_win = mlx_new_window(pcheck->mlx, i, j, "mnassi");
	pcheck->ptr = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/wall/wall5.xpm",
			&pcheck->x, &pcheck->y);
	pcheck->p = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/floor/dirt.xpm",
			&pcheck->x, &pcheck->y);
	pcheck->door = mlx_xpm_file_to_image(pcheck->mlx, "./pixe/door/close.xpm",
			&pcheck->x, &pcheck->y);
	pcheck->right = mlx_xpm_file_to_image(pcheck->mlx,
			"./pixe/player/right.xpm", &pcheck->x, &pcheck->y);
	seccheck->player = mlx_xpm_file_to_image(pcheck->mlx,
			"./pixe//player/right.xpm", &pcheck->x, &pcheck->y);
	checkpath1(pcheck, seccheck);
	if (pcheck->ptr == NULL || pcheck->p == NULL || pcheck->door == NULL
		|| pcheck->right == NULL || seccheck->player == NULL
		|| pcheck->left == NULL)
		ft_error(6);
}

void	checkpath1(t_var *first, t_text *sec)
{
	sec->res = mlx_xpm_file_to_image(first->mlx, "./pixe/collectibles/geo.xpm",
			&first->x, &first->y);
	first->left = mlx_xpm_file_to_image(first->mlx, "./pixe/player/left.xpm",
			&first->x, &first->y);
	first->up = mlx_xpm_file_to_image(first->mlx, "./pixe/player/up.xpm",
			&first->x, &first->y);
	first->down = mlx_xpm_file_to_image(first->mlx, "./pixe/player/down.xpm",
			&first->x, &first->y);
	first->secdoor = mlx_xpm_file_to_image(first->mlx, "./pixe/door/open.xpm",
			&first->x, &first->y);
	if (sec->res == NULL || first->left == NULL || first->up == NULL
		|| first->down == NULL || first->secdoor == NULL)
		ft_error(6);
}
