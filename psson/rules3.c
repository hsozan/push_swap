#include "pushswap.h"

/*void	ra(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cpy;

	if (!(*list_a) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	cpy = (*list_a)->next;
	while ((*list_a)->next)
		*list_a = (*list_a)->next;
	(*list_a)->next = tmp;
	tmp->next = NULL;
	*list_a = cpy;
	if (p == 1)
		write(1, "ra\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute ra:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cpy;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	cpy = (*list_b)->next;
	while ((*list_b)->next)
		*list_b = (*list_b)->next;
	(*list_b)->next = tmp;
	tmp->next = NULL;
	*list_b = cpy;
	if (p == 1)
		write(1, "rb\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rb:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rr(t_list **list_a, t_list **list_b, int p)
{
	ra(list_a, list_b, 0);
	rb(list_b, list_b, 0);
	if (p == 1)
		write(1, "rr\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rr:\n\n");
		visualizer(*list_a, *list_b);
	}
}*/
static void	ft_rotate(t_list *list)
{
	t_list	*new_last;
	t_list	*new_first;

	new_last = list;
	list = list->next;
	new_first = list;
	while (new_first->next)
	{
		new_first = new_first->next;
	}
	new_first->next = new_last;
	new_first->next->next = NULL;
}

static void rr(t_list *a, t_list *b, int p)
{
	ft_rotate(a);
	ft_rotate(b);
	if (p == 1)
		write(1, "rr\n", 3);
	if (p == 2)
		ft_putstr("\x1b[36mExecute rr:\n\n");
}

void	ra_rb_rr(t_list *a, t_list *b, char c, int p)
{
	if (c == 'a')
	{
		ft_rotate(a);
	if (p == 1)
		write(1, "ra\n", 3);
	if (p == 2)
		ft_putstr("\x1b[36mExecute ra:\n\n");
	}
	else if (c == 'b')
	{
		ft_rotate(b);
	if (p == 1)
		write(1, "rb\n", 3);
	if (p == 2)
		ft_putstr("\x1b[36mExecute rb:\n\n");
	}
	else
		rr(a, b, p);
	if (p == 2)
		visualizer(a, b);
}