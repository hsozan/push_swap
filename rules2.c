/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:17:29 by hsozan            #+#    #+#             */
/*   Updated: 2022/09/22 11:17:31 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ss(t_list **a, t_list **b, int p)
{
	ft_swap(&((*a)->n), &((*a)->next->n));
	ft_swap(&((*b)->n), &((*b)->next->n));
	if (p == 1)
		ft_putstr("ss\n");
	if (p == 2)
		ft_putstr("\x1b[36mExecute ss:\n\n");
}

void	sa_sb_ss(t_list **a, t_list **b, char c, int p)
{
	if (c == 'a' && ft_lstsize(*a) > 1)
	{
		ft_swap(&((*a)->n), &((*a)->next->n));
		if (p == 1)
			ft_putstr("sa\n");
		if (p == 2)
			ft_putstr("\x1b[36mExecute sa:\n\n");
	}
	else if (c == 'b' && ft_lstsize(*b) > 1)
	{
		ft_swap(&((*b)->n), &((*b)->next->n));
		if (p == 1)
			ft_putstr("sb\n");
		if (p == 2)
			ft_putstr("\x1b[36mExecute sb:\n\n");
	}
	else if (ft_lstsize(*b) > 1 && ft_lstsize(*a) > 1)
		ss(a, b, p);
	if (p == 2)
		visualizer(*a, *b);
}
