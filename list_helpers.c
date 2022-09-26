/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:56:33 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 10:56:35 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_link(t_list **list, int n)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	new = malloc(sizeof(t_list));
	if (new)
	{
		new->n = n;
		new->next = NULL;
		if (*list)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
		{
			*list = new;
			return ;
		}
	}
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp)
			free(tmp);
	}
	list = NULL;
}

t_list	*ft_lsthere(t_list *lst, int c)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL && i < c)
	{
		lst = lst -> next;
		i++;
	}
	return (lst);
}

int	ft_lstdata(t_list *lst, int c)
{
	int	data;
	int	i;

	i = 0;
	while (i <= c && lst != NULL)
	{
		data = lst -> n;
		lst = lst -> next;
		i++;
	}
	return (data);
}
