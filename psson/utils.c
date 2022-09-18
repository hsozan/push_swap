#include "pushswap.h"

int		is_sort(t_list *list_a)
{
	while (list_a->next)
	{
		if (list_a->n > list_a->next->n)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

int		find_max(t_list *list, int skip)
{
	int	max;

	max = -2147483648;
	while (list->next)
	{
		if (list->n > max && list->n != skip)
			max = list->n;
		list = list->next;
	}
	if (list->n > max && list->n != skip)
		max = list->n;
	return (max);
}

int		find_min(t_list *list)
{
	int	min;

	min = 2147483647;
	while (list->next)
	{
		if (list->n < min)
			min = list->n;
		list = list->next;
	}
	if (list->n < min)
		min = list->n;
	return (min);
}
