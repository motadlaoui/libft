/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:53:25 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/25 14:38:54 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*str;
	const char	*strm;

	str = dst;
	strm = src;
	if (str == NULL && strm == NULL)
		return (NULL);
	if (strm < str)
	{
		while (len--)
			*(str + len) = *(strm + len);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			str[i] = strm[i];
			i++;
		}
	}
	return (dst);
}
