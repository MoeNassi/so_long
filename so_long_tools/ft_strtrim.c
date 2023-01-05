/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:19:16 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/06 10:19:00 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static	int	end(char const *s1, char const *set)
{
	int	h;
	int	l;

	h = 0;
	l = ft_strlen(s1) - 1;
	while (l >= 0)
	{
		if (ft_strrchr(set, s1[l]) == 0)
			break ;
		l--;
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		f;
	int		b;
	int		p;

	if (!s1 || !set)
		return (NULL);
	f = start(s1, set);
	b = (end(s1, set) - f) + 1;
	p = 0;
	if (end(s1, set) == -1)
		return (ft_substr(s1, f, 0));
	s = malloc(b + 1);
	if (!s)
		return (NULL);
	while (p < b)
	{
		s[p] = s1[f];
		f++;
		p++;
	}
	s[p] = '\0';
	return (s);
}
