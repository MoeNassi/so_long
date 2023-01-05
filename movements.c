/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:23:42 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/05 14:15:57 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "libft/libft.h"

void	upmove(t_var *top, int keycode)
{
	static int	i;

	if (top->map[top->p2 / 32 - 1][top->p1 / 32] != '1' && keycode == 13)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (top->map[top->p2 / 32 + 1][top->p1 / 32] != '1' && keycode == 1)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (top->map[top->p2 / 32][top->p1 / 32 - 1] != '1' && keycode == 0)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (top->map[top->p2 / 32][top->p1 / 32 + 1] != '1' && keycode == 2)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
}
