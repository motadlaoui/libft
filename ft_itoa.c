/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:37:09 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/25 14:54:59 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static char	*revstr(char *str, int c, int a)
{
	int		i;
	int		b;
	char	d;
	int		k;

	i = 0;
	b = c - 1;
	k = c / 2;
	if (a < 0)
	{
		i += 1;
		k += 1;
	}
	while (i < k)
	{
		d = str[i];
		str[i] = str[b];
		str[b] = d;
		i++;
		b--;
	}
	return (str);
}

static char	*convert(char *str, int d)
{
	int	i;

	i = 0;
	if (d < 0)
	{
		str[i] = '-';
		i++;
		d *= -1;
	}
	while (d / 10 != 0)
	{
		str[i] = (d % 10) + '0';
		i++;
		d /= 10;
	}
	str[i] = (d + '0');
	i++;
	str[i] = '\0';
	return (str);
}

static int	n_size(int a)
{
	int	i;

	i = 0;
	while (a / 10 != 0)
	{
		i++;
		a /= 10;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	int		b;
	char	*s;

	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	else if (n < 0)
		b = n_size(-n) + 1;
	else
		b = n_size(n);
	s = (char *)malloc(sizeof(char) * (b + 1));
	if (s == NULL)
		return (NULL);
	s = convert(s, n);
	s = revstr(s, b, n);
	return (s);
}
