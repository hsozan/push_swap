/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters3-5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:20:56 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:20:58 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_for_3(t_list **l1, t_list **l2, int p)
{
	int	a;
	int	b;
	int	c;

	a = (*l1)->n;
	b = (*l1)->next->n;
	c = (*l1)->next->next->n;
	if (a > b && c > b && c > a)
		sa_sb_ss(l1, l2, 'a', p);
	else if (a > b && a > c && b > c)
	{
		sa_sb_ss(l1, l2, 'a', p);
		rra_rrb_rrr(l1, l2, 'a', p);
	}
	else if (a > b && c > b && a > c)
		ra_rb_rr(l1, l2, 'a', p);
	else if (a < b && a < c && b > c)
	{
		sa_sb_ss(l1, l2, 'a', p);
		ra_rb_rr(l1, l2, 'a', p);
	}
	else if (a < b && a > c && b > c)
		rra_rrb_rrr(l1, l2, 'a', p);
}

static void	five_finish(t_list **l1, t_list **l2, int p)
{
	sort_for_3(l1, l2, p);
	while (ft_lstsize(*l2) != 0)
	{
		if ((*l2)->index == 0)
			pa_pb(l1, l2, 'a', p);
		else
		{
			pa_pb(l1, l2, 'a', p);
			ra_rb_rr(l1, l2, 'a', p);
		}
	}
}

void	sort_for_5(t_list **l1, t_list **l2, int len, int p)
{
	t_list	*tmp;

	tmp = *l1;
	while (ft_lstsize(*l1) != 3)
	{
		if (tmp->index == 0)
		{
			tmp = tmp->next;
			pa_pb(l1, l2, 'b', p);
		}
		else if (tmp->index == len - 1)
		{
			tmp = tmp->next;
			pa_pb(l1, l2, 'b', p);
		}
		else
		{
			tmp = tmp->next;
			ra_rb_rr(l1, l2, 'a', p);
		}
	}
	five_finish(l1, l2, p);
}
