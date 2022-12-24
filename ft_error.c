/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:53:18 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/23 18:11:54 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_error(int exp)
{
	if (exp == 1)
		printf("%s\n", "No arguments detected");
	if (exp == 2)
		printf("%s\n", "Error in map please fix your map");
	if (exp == 3)
		printf("%s\n", "Winner Winner Chicken Dinner #1 battleroyale fortnite");
	if (exp == 4)
		printf("%s\n", "error");
	if (exp == 5)
		printf("%s\n", "Map Not Found");
	if (exp == 6)
		printf("%s\n", "Path Not Found");
	if (exp == 7)
		printf("%s\n", "Learn to play NOOB HAHA EZ");
	exit(0);
}