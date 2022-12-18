/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:49:30 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/22 20:18:18 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*alloc(size_t size)
{
	unsigned char	*pt;
	size_t			i;

	i = 0;
	pt = malloc(size);
	if (pt == NULL)
		return (NULL);
	while (i < size)
	{
		pt[i] = 0;
		i++;
	}
	return (pt);
}

char	*ft_read_line(int fd, char *reading)
{
	int		count;
	char	*stock;

	count = 1;
	stock = malloc(BUFFER_SIZE + 1);
	if (!stock)
		return (NULL);
	while (count > 0 && !ft_strchr(reading, '\n'))
	{
		count = read(fd, stock, BUFFER_SIZE);
		if (count < 0 || (count == 0 && !reading)
			|| (count == 0 && reading[0] == 0))
			return (free(stock), free(reading), NULL);
		stock[count] = '\0';
		reading = ft_strjoin(reading, stock);
	}
	free(stock);
	return (reading);
}

char	*ft_stock_line(char *ret)
{
	int		in;
	char	*sec;
	int		i;

	i = 0;
	in = 0;
	while (ret[in] != '\n' && ret[in])
		in++;
	sec = alloc(in + 2);
	if (!sec)
		return (free(ret), NULL);
	if (ret[in] == '\n')
		in++;
	while (ret[i] && i < in)
	{
		sec[i] = ret[i];
		i++;
	}
	sec[i] = '\0';
	return (sec);
}

char	*ft_next_line(char *next)
{
	int		line;
	char	*alc;
	int		lenght;
	int		copy;

	line = 0;
	copy = 0;
	while (next[line] && next[line] != '\n')
		line++;
	lenght = ft_strlen(next);
	if (lenght == line)
		return (free(next), NULL);
	alc = malloc((lenght - line) + 1);
	if (!alc)
		return (free(next), NULL);
	line++;
	while (next[line])
		alc[copy++] = next[line++];
	alc[copy] = '\0';
	free(next);
	return (alc);
}

char	*get_next_line(int fd)
{
	static char		*stats;
	char			*notsta;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stats = ft_read_line(fd, stats);
	if (!stats)
		return (NULL);
	if (!*stats)
		return (free(stats), NULL);
	notsta = ft_stock_line(stats);
	stats = ft_next_line(stats);
	return (notsta);
}
