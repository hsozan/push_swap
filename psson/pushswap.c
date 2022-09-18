#include "pushswap.h"
void	index_push(t_list (*stack))
{
	int	data1;
	int	data2;
	int	i;
	int	k;
	int	indis;

	i = 0;
	while (i < ft_lstsize(stack))
	{
		indis = 0;
		k = 0;
		data1 = ft_lstdata(stack, i);
		while (k < ft_lstsize(stack))
		{
			data2 = ft_lstdata((stack), k);
			if (data1 > data2)
				indis++;
			k++;
		}
		ft_lsthere(stack, i)->index = indis;
		i++;
		if (i == ft_lstsize(stack))
			return ;
	}
}

void sort(t_list *a,t_list *b, int p)
{
	int len=ft_lstsize(a);
	if (len == 3)
		sort_for_3(a, b, p);
	else if (len <= 5)
		sort_for_5(a, b, len, p);
	else if (len >= 6 && len <= 100)
		sort_for_100(a, b, len, p);
	else
		sort_for_500(a, b, len, p);
}

int				main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	t_info	*info;
	if (ac < 2 || (ac < 3 && !ft_strcmp(av[1], "-v")))
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
	if (info->vis == 2)
	{
		ft_printf("\x1b[36m\nStart Visualization...\n\nStart Stack : \n\n");
		visualizer(list_a, 0);
	}
	index_push(list_a);
	sort(list_a, list_b,info->vis);
	free_list(list_a);
	free(info);
}
