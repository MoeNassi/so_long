/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:17:17 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/07 11:17:51 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int		i;

	i = 0;
	if (n < 0 || n == 0)
		i = i + 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*l;
	int		i;
	long	s;

	s = (long)n;
	i = count(s);
	l = malloc(i + 1);
	if (!l)
		return (NULL);
	l[i] = '\0';
	if (s == 0)
		l[0] = s + '0';
	if (s < 0)
	{
		l[0] = '-';
		s = s * (-1);
	}
	while (s > 0)
	{
		l[i - 1] = (s % 10) + '0';
		s = s / 10;
		i--;
	}
	return (l);
}
