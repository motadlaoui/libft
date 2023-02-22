/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:48:33 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/26 17:43:35 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	*fun(char *p, const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	b;

	i = 0;
	k = 0;
	b = 0;
	while (s[i])
	{
		while (i >= start && b < len)
		{
			p[k] = s[i + b];
			k++;
			b++;
		}
		i++;
	}
	p[b] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
	{
		p = (char *)malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
		len = ft_strlen(s) - start;
	}
	else
		p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	fun(p, s, start, len);
	return (p);
}
