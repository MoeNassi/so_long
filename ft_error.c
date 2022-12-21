/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:53:18 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/21 11:48:55 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_error(int exp)
{
	if (exp == 1)
		printf("%s\n", "No arguments detected");
	if (exp == 2)
	{
		printf("%s\n", "Error in map please fix you map");
		exit(1);
	}
	if (exp == 3)
	{
		printf("%s\n", "Winner Winner Chicken Dinner #1 battleroyale fortnite");
		exit(0);
	}
	if (exp == 4)
	{
		printf("%s", "error");
		exit(0);
	}
	if (exp == 5)
		printf("%s", "Map Not Found");
	if (exp == 6)
	{
		printf("%s", "Path Not Found");
		exit(0);
	}
	return (0);
}