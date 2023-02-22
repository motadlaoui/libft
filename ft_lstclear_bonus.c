/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:28:03 by mtadlaou          #+#    #+#             */
/*   Updated: 2022/10/29 08:41:56 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*t;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	t = *lst;
	p = *lst;
	while (p != NULL)
	{
		p = p->next;
		del(t->content);
		free(t);
		t = p;
	}
	*lst = NULL;
}
