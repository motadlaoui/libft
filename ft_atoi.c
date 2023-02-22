/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:46:20 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/11/01 13:26:37 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

static int	skip_escpace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned long	var;
	int				i;
	int				min;

	i = skip_escpace(str);
	min = 1;
	if (str[i] == '-')
		min *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	var = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		var = var * 10 + (str[i] - '0');
		if (var > LONG_MAX && min > 0)
			return (-1);
		if (var > LONG_MAX && min < 0)
			return (0);
		i++;
	}
	return ((int)var * min);
}
