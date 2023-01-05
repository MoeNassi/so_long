/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:53:18 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/05 15:28:29 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "so_long_tools/libft.h"

int	ft_error(int exp)
{
	if (exp == 1)
		ft_putstr_fd("No arguments detected\n", 1);
	if (exp == 2)
		ft_putstr_fd("Error in map please fix your map\n", 1);
	if (exp == 3)
		ft_putstr_fd("Winner Winner Chicken Dinner #1\n", 1);
	if (exp == 4)
		ft_putstr_fd("error\n", 1);
	if (exp == 5)
		ft_putstr_fd("Map Not Found\n", 1);
	if (exp == 6)
		ft_putstr_fd("Path Not Found\n", 1);
	if (exp == 7)
		ft_putstr_fd("Learn to play NOOB HAHA EZ\n", 1);
	exit(0);
}
