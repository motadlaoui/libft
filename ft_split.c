/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:25:02 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/31 09:56:17 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	*free_fun(char **s, size_t a)
{
	size_t	i;

	i = 0;
	while (i < a)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**full_split(const char *str, char **spl, char c)
{
	int	i;
	int	j;
	int	h;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			h = i;
			while (str[i] != c && str[i])
				i++;
			spl[j] = ft_substr(str, h, (i - h));
			if (spl[j] == NULL)
				return (free_fun(spl, j));
			j++;
		}
		else
			i++;
	}
	spl[j] = NULL;
	return (spl);
}

static int	string_num(const char *str, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
				a++;
		}
		i++;
	}
	if (str[0] != c)
		return (a + 1);
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (s == NULL)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (string_num(s, c) + 1));
	if (!p)
		return (NULL);
	p = full_split(s, p, c);
	return (p);
}
