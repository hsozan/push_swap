/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:16:25 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:16:29 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*void	pa(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;

	if (!(*list_b))
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = *list_a;
	*list_a = tmp;
	if (p == 1)
		write(1, "pa\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute pa:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	pb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;

	if (!(*list_a))
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
	if (p == 1)
		write(1, "pb\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute pb:\n\n");
		visualizer(*list_a, *list_b);
	}
}*/
static void	ft_push(t_list **left, t_list **right)
{
	t_list	*tmp;

	tmp = *left;
	*left = (*left)->next;
	tmp->next = *right;
	*right = tmp;
}

void	pa_pb(t_list **a, t_list **b, char c, int p)
{
	if (c == 'a')
	{
		ft_push(b, a);
		if (p == 1)
			write(1, "pa\n", 3);
		if (p == 2)
			ft_putstr("\x1b[36mExecute pa:\n\n");
	}
	else if (c == 'b')
	{
		ft_push(a, b);
		if (p == 1)
			write(1, "pb\n", 3);
		if (p == 2)
			ft_putstr("\x1b[36mExecute pb:\n\n");
	}
	if (p == 2)
		visualizer(*a, *b);
}
