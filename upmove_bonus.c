/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upmove_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:41:40 by mnassi            #+#    #+#             */
/*   Updated: 2023/01/03 15:57:01 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "libft/libft.h"

void	upmove_bonus(t_var *top, int keycode)
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
	ft_countmoves(top, i);
}
