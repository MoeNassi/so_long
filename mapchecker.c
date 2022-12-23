/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:46:41 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/22 11:56:58 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	mapchecker(t_var *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i])
	{
		if (check->map[i][0] != '1')
			ft_error(2);
		i++;
	}
	j = 0;
	i = 0;
	while (check->map[i])
		i++;
	i--;
	while (check->map[i][j] != '\n' && check->map[i][j])
	{
		if (check->map[i][j] != '1')
			ft_error(2);
		j++;
	}
}
