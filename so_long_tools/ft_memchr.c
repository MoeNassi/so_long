/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:56:58 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/08 10:15:48 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*p;
	char		l;

	l = (char )c;
	p = (char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == l)
			return (&p[i]);
		i++;
	}
	return (0);
}
