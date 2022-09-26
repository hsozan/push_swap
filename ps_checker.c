/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:58:49 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 10:59:15 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	rr(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp("ra", line)))
		ra_rb_rr(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp("rb", line)))
		ra_rb_rr(list_a, list_b, 'b', 0);
	else if (!(ft_strcmp("rr", line)))
		ra_rb_rr(list_a, list_b, 'q', 0);
	else if (!(ft_strcmp("pa", line)))
		pa_pb(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp("pb", line)))
		pa_pb(list_a, list_b, 'b', 0);
	else
		return (0);
	if (is_sort(*list_a) && !(*list_b))
		return (2);
	return (1);
}

static int	rrr(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp("rra", line)))
			rra_rrb_rrr(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp("rrb", line)))
		rra_rrb_rrr(list_a, list_b, 'b', 0);
	else if (!(ft_strcmp("rrr", line)))
		rra_rrb_rrr(list_a, list_b, 'q', 0);
	else if (!(ft_strcmp("sa", line)))
		sa_sb_ss(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp("sb", line)))
		sa_sb_ss(list_b, list_b, 'b', 0);
	else if (!(ft_strcmp("ss", line)))
		sa_sb_ss(list_a, list_b, 'q', 0);
	else
		return (rr(line, list_a, list_b));
	return (1);
}

int	checker(t_list **list_a, t_list **list_b)
{
	int		ret;
	char	*line;
	int		i;
	char *a;
	while (1)
	{
		if(!get_next_line(0, &line))
			return (0);
		ret = rrr(line, list_a, list_b);
		if (ret == 2)
			return (1);
		if (ret == 0)
			return (-1);
		if (ret != 1)
			return (0);
		if (line)
			free(line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int		p;

	if (ac < 2)
		return (0);
	p = 1;
	list_a = create_list(ac, av, &p);
	list_b = NULL;
	if (!(list_a))
		return (write(2, "Error\n", 6));
	p = checker(&list_a, &list_b);
	if (p == 1)
		write(1, "OK", 2);
	else if (p == 0)
		write(1, "KO", 2);
	else if (p == -1)
		write(2, "Error", 5);
	if (list_b)
		free_list(list_b);
	free_list(list_a);
}
