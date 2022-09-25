/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters100-500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:22:03 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:22:05 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	search_max(t_list **b, int i)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->index == i)
			break ;
		tmp = tmp->next;
		n++;
	}
	return (n);
}

static void	sort_b(t_list **a, t_list **b, int len, int p)
{
	int	max_i;
	int	half;
	int	place;

	max_i = len - 1;
	while (*b)
	{
		half = (max_i + 1) / 2;
		place = search_max(b, max_i);
		if ((*b)->index == max_i)
		{
			pa_pb(a, b, 'a', p);
			max_i--;
		}
		else if (place <= half && (*b)->index != max_i)
			ra_rb_rr(a, b, 'b', p);
		else if (place > half && (*b)->index != max_i)
			rra_rrb_rrr(a, b, 'b', p);
	}
}

void	sort_for_100(t_list **a, t_list **b, int len, int p)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i&& i>1)
		{
			pa_pb(a, b, 'b', p);
			ra_rb_rr(a, b, 'b', p);
			i++;
		}
		else if ((*a)->index <= (i + 15))
		{
			pa_pb(a, b, 'b', p);
			i++;
		}
		else if ((*a)->index >= i)
			ra_rb_rr(a, b, 'a', p);
	}
	sort_b(a, b, len, p);
}

void	sort_for_500(t_list **a, t_list **b, int len, int p)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i && i > 1)
		{
			pa_pb(a, b, 'b', p);
			ra_rb_rr(a, b, 'b', p);
			i++;
		}
		else if ((*a)->index <= (i + 30))
		{
			pa_pb(a, b, 'b', p);
			i++;
		}
		else if ((*a)->index >= i)
			ra_rb_rr(a, b, 'a', p);
	}
	sort_b(a, b, len, p);
}
