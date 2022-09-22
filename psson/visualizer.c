/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:42 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:24:44 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	print(t_list *list, int max, int min)
{
	if (list && list->n == max)
		ft_printf("\x1b[31m%d", list->n);
	else if (list && list->n == min)
		ft_printf("\x1b[32m%d", list->n);
	else if (list)
		ft_printf("\x1b[33m%d", list->n);
}

void	init_max(t_list *list, int *max, int *min)
{
	*max = find_max(list, -2147483648);
	*min = find_min(list);
}

void	visualizercontinued(t_list *list_a)
{
	if (list_a && list_a->n / 10)
		ft_putstr("\t\t");
	else
		ft_putstr("\t\t\t");
}

void	visualizer(t_list *list_a, t_list *list_b)
{
	int	i;
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;

	i = 0;
	if (list_a)
		init_max(list_a, &max_a, &min_a);
	if (list_b)
		init_max(list_b, &max_b, &min_b);
	while (list_a || list_b)
	{
		ft_printf("\x1b[36mPosition %d -> ", i++);
		print(list_a, max_a, min_a);
		visualizercontinued(list_a);
		print(list_b, max_b, min_b);
		ft_putchar('\n');
		if (list_a)
			list_a = list_a->next;
		if (list_b)
			list_b = list_b->next;
	}
	ft_printf("\n\n\x1b[33m%i moves\n",i);
}
