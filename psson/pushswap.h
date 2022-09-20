#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef	struct		s_info
{
	int				vis;
}					t_info;

//rules
void			pa_pb(t_list **a, t_list **b, char c, int p);
void			sa_sb_ss(t_list **a, t_list **b, char c, int p);
void			ra_rb_rr(t_list **a, t_list **b, char c, int p);
void			rra_rrb_rrr(t_list **a, t_list **b, char c, int p);

//list_create.c
static int      check_arg(char *s, int i);
static t_list	*fill_list(t_info *info, t_list *list, int ac, char **av);
static int	    check_dup(t_list *list);
t_list	        *create_list(int ac, char **av, t_info **info);

//list_helpers.c
void			add_link(t_list **list, int n);
void			free_list(t_list *list);
int				free_all(t_list *list, t_info *info);
t_list			*ft_lsthere(t_list *lst, int c);
int				ft_lstdata(t_list *lst, int c);

//sorters
void	sort_for_3(t_list **l1, t_list **l2, int p);
void	sort_for_5(t_list **l1, t_list **l2, int len, int p);
void	sort_for_100(t_list **a, t_list **b, int len, int p);
void	sort_for_500(t_list **a, t_list **b, int len, int p);

//index.c
void			index_push(t_list *list);

//ps_checker.c
static int	    split(char *line, t_list **list_a, t_list **list_b);
int			    checker(t_list **list_a, t_list **list_b);
//visualizer.c
void		    visualizer(t_list *list_a, t_list *list_b);
static void		    print(t_list *list, int max, int min);
void		    init_max(t_list *list, int *max, int *min);
//utils.c
int		        is_sort(t_list *list_a);
int			    find_size(t_list *list);
int			    find_max(t_list *list, int skip);
int			    find_min(t_list *list);
int			    find_pos(int n, t_list *list);

#endif