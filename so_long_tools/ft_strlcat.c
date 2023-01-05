/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:49:35 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/08 09:54:41 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if ((!dst && !dstsize) || !dstsize)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize < dlen)
		return (slen + dstsize);
	j = 0;
	i = 0;
	while (dst[i])
		i++;
	while (src[j] && j + dlen < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dlen + slen);
}
