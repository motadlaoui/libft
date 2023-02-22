/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:52:28 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/25 14:54:26 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	size(int a, int b)
{
	int	i;

	i = 0;
	while (a < b)
	{
		i++;
		a++;
	}
	return (i);
}

static int	fun1(const char *str, const char *s)
{
	int	b;
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_strchr(s, str[i]) == 0))
		{
			b = i;
			return (b);
		}
		i++;
	}
	return (0);
}

static int	fun2(const char *str, const char *s)
{
	int	c;
	int	j;
	int	a;

	a = ft_strlen(str);
	c = 0;
	j = a;
	while (j > 0)
	{
		if (ft_strchr(s, str[j - 1]) == 0)
			return (j);
		j--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	a;
	int	b;
	int	c;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	b = fun1(s1, set);
	c = fun2(s1, set);
	a = size(b, c);
	return (ft_substr(s1, b, a));
}
