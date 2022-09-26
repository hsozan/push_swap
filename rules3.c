/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:18:26 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:18:29 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_rotate(t_list **list)
{
	t_list	*new_last;
	t_list	*new_first;

	new_last = *list;
	*list = (*list)->next;
	new_first = *list;
	while (new_first->next)
	{
		new_first = new_first->next;
	}
	new_first->next = new_last;
	new_first->next->next = NULL;
}

static void	rr(t_list **a, t_list **b, int p)
{
	ft_rotate(a);
	ft_rotate(b);
	if (p == 1)
		write(1, "rr\n", 3);
	if (p == 2)
		ft_putstr("\x1b[36mExecute rr:\n\n");
}

void	ra_rb_rr(t_list **a, t_list **b, char c, int p)
{
	if (c == 'a' && ft_lstsize(*a) > 1)
	{
		ft_rotate(a);
		if (p == 1)
			write(1, "ra\n", 3);
		if (p == 2)
			ft_putstr("\x1b[36mExecute ra:\n\n");
	}
	else if (c == 'b' && ft_lstsize(*b) > 1)
	{
		ft_rotate(b);
		if (p == 1)
			write(1, "rb\n", 3);
		if (p == 2)
			ft_putstr("\x1b[36mExecute rb:\n\n");
	}
	else if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
		rr(a, b, p);
	if (p == 2)
		visualizer(*a, *b);
}
