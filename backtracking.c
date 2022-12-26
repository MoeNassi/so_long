/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:22:22 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/26 16:40:59 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	ft_back(char **arr, int i, int j)
{
	if (arr[i][j] == 'E')
		return (1);
	if (arr[i][j] == '1')
		return (0);
	arr[i][j] = '1';
	if (ft_back(arr, i, j + 1))
		return (1);
	if (ft_back(arr, i, j - 1))
		return (1);
	if (ft_back(arr, i + 1, j))
		return (1);
	if (ft_back(arr, i - 1, j))
		return (1);
	return (0);
}
