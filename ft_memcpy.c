/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:55 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/29 07:26:45 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str;
	unsigned const char	*strm;
	size_t				i;

	str = dst;
	strm = src;
	i = 0;
	if (str == NULL && strm == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	while (i < n)
	{
		str[i] = strm[i];
		i++;
	}
	return (dst);
}
