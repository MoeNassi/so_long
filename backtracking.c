/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:22:22 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/10 10:39:55 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	ft_back(char **arr, int x, int y)
{
	if (arr[x][y] == 'E')
		return (1);
	if (arr[x][y] == '1')
		return (0);
	arr[x][y] = '1';
	if (ft_back(arr, x, y + 1))
		return (1);
	if (ft_back(arr, x, y - 1))
		return (1);
	if (ft_back(arr, x + 1, y))
		return (1);
	if (ft_back(arr, x - 1, y))
		return (1);
	return (0);
}
