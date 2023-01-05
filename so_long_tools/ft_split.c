/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:54:44 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/06 12:01:39 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static void	freesplit(char **s, int i)
{
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**mok;
	size_t	i;
	size_t	j;
	int		y;

	i = 0;
	j = 0;
	y = -1;
	if (!s)
		return (NULL);
	mok = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!mok)
		return (NULL);
	while (++y < count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		mok[y] = ft_substr(s, j, i - j);
		if (!mok[y])
			return (freesplit(mok, 0), NULL);
	}
	return (mok[y] = NULL, mok);
}
