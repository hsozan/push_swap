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
	t_list	*max_min;
	max_min = *l1;
	while (ft_lstsize(*l1) != 3)
	{
		if (max_min->index == 0)
		{
			max_min = max_min->next;
			pa_pb(l1, l2, 'b', p);
		}
		else if (max_min->index == len)
		{
			max_min = max_min->next;
			pa_pb(l1, l2, 'b', p);
		}
		else
		{
			max_min = max_min->next;
			ra_rb_rr(l1, l2, 'a', p);
		}
	}
	five_finish(l1, l2, p);
}