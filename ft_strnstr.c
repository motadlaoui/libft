/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:55:11 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/11/01 13:20:56 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str == 0 && len == 0)
		return (0);
	if (*to_find == '\0')
		return ((char *)str);
	while (i < len && *str)
	{
		while ((str[j] == to_find[j]) && ((i + j) < len) && str[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)str);
		str++;
		i++;
		j = 0;
	}
	return (0);
}
