/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:19:40 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:19:44 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*void	rra(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	tmp = *list_a;
	cp = *list_a;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list_a;
	*list_a = tmp;
	if (p == 1)
		write(1, "rra\n", 4);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rra:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rrb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	cp = *list_b;
	if (!(*list_b))
		return ;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list_b;
	*list_b = tmp;
	if (p == 1)
		write(1, "rrb\n", 4);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rrb:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rrr(t_list **list_a, t_list **list_b, int p)
{
	rra(list_a, list_b, 0);
	rrb(list_a, list_b, 0);
	if (p == 1)
		write(1, "rrr\n", 4);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rrr:\n\n");
		visualizer(*list_a, *list_b);
	}
}*/
static t_list	*find_pre_last(t_list *list)
{
	t_list	*pre_last;

	pre_last = NULL;
	if (list && list->next)
	{
		pre_last = list;
		while (pre_last->next->next)
			pre_last = pre_last->next;
	}
	return (pre_last);
}

static void	ft_reverse_rotate(t_list **list)
{
	t_list	*pre_last;
	t_list	*last;
	t_list	*tmp;

	if (*list && (*list)->next)
	{
		tmp = *list;
		pre_last = find_pre_last(*list);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*list = last;
	}
}

static void	rrr(t_list **a, t_list **b, int p)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (p == 1)
		write(1, "rrr\n", 4);
	if (p == 2)
		ft_putstr("\x1b[36mExecute rrr:\n\n");
}

void	rra_rrb_rrr(t_list **a, t_list **b, char c, int p)
{
	if (c == 'a' && ft_lstsize(*a) > 1)
	{
		ft_reverse_rotate(a);
		if (p == 1)
			write(1, "rra\n", 4);
		if (p == 2)
			ft_putstr("\x1b[36mExecute rra:\n\n");
	}
	else if (c == 'b' && ft_lstsize(*b) > 1)
	{
		ft_reverse_rotate(b);
		if (p == 1)
			write(1, "rrb\n", 4);
		if (p == 2)
			ft_putstr("\x1b[36mExecute rrb:\n\n");
	}
	else if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
		rrr(a, b, p);
	if (p == 2)
		visualizer(*a, *b);
}
