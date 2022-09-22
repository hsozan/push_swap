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

static int	split(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "ra")))
		ra_rb_rr(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp(line, "rb")))
		ra_rb_rr(list_a, list_b, 'b', 0);
	else if (!(ft_strcmp(line, "rr")))
		ra_rb_rr(list_a, list_b, 'q', 0);
	else if (!(ft_strcmp(line, "sa")))
		sa_sb_ss(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp(line, "sb")))
		sa_sb_ss(list_b, list_b, 'b', 0);
	else if (!(ft_strcmp(line, "ss")))
		sa_sb_ss(list_a, list_b, 'q', 0);
	else if (!(ft_strcmp(line, "rra")))
		rra_rrb_rrr(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp(line, "rrb")))
		rra_rrb_rrr(list_a, list_b, 'b', 0);
	else if (!(ft_strcmp(line, "rrr")))
		rra_rrb_rrr(list_a, list_b, 'q', 0);
	else if (!(ft_strcmp(line, "pa")))
		pa_pb(list_a, list_b, 'a', 0);
	else if (!(ft_strcmp(line, "pb")))
		pa_pb(list_a, list_b, 'b', 0);
	else
		return (0);
	return (1);
}

int	checker(t_list **list_a, t_list **list_b)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (ret == -1)
		{
			return (0);
		}
		if (!(split(line, list_a, list_b)))
		{
			return (0);
		}
		if(line)
			free(line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	t_info	*info;

	if (ac < 2)
		return (0);
	info = malloc(sizeof(t_info));
	info->vis = 1;
	list_a = create_list(ac, av, &info);
	list_b = NULL;
	if (!(list_a))
	{
		free(info);
		return (write(2, "Error\n", 6));
	}
	if (!(checker(&list_a, &list_b)))
	{
		free_list(list_a);
		free_list(list_b);
		free(info);
		return (write(2, "Error", 5));
	}
	if (list_a && is_sort(list_a) && !list_b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (list_b)
		free_list(list_b);
	free_list(list_a);
	free(info);
	return (0);
}
