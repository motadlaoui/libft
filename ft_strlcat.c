/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:35:23 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/28 12:32:45 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;
	size_t	d;

	s = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s);
	d = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= d)
		return (dstsize + s);
	i = 0;
	while (src[i] && i < dstsize - d - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[i + d] = '\0';
	return (s + d);
}
