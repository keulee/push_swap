#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define A 0
# define B 1
# define AB 2

typedef struct s_node{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_call{
	int		ra;
	int		pb;
	int		rb;
	int		pa;
	int		big_p;
	int		small_p;
}				t_call;

typedef struct s_info {
	int		i;
	int		j;
	char	**tmp;
	long	arg;
	int		listsize;
	t_node	*stack_a;
	t_node	*stack_b;
}				t_info;

void	print_node_a(t_node *node);
void	print_node_b(t_node *node);
void	print_node(t_node *node);

/*
** push swap
*/
void	sort_less_five(t_info *info);
void	sort_recursive_push_swap(t_info *info);

/*
** init
*/
void	ft_init(t_info *info);
void	call_init(t_call *call);

/*
** create stack
*/
void	create_stack(t_info *info, char **av);
void	value_check(char *str, t_info *info);
int		check_double(char **s1, char *s2);
int		count_arg(char *str);
void	insert_node(t_node **node, int value);
void	find_double(t_node *node, int value);
int		get_listsize(t_node **a);

/*
** sort a to b.c
*/
void	sort_a_to_b(int size, t_node **a, t_node **b, int *flag);
void	rotate_push_b(t_node **a, t_node **b, t_call *call);
void	rev_rotate_ra_flag(t_node **a, t_node **b, t_call *call, int *flag);
void	rev_rotate_rb_flag(t_node **a, t_node **b, t_call *call, int *flag);
int		exceptions_a_to_b(int size, t_node **a, t_node **b);

/*
** exception a to b
*/
void	exception_size_under_3a(t_node **a, t_node **b, int size);
void	exception_size_3a(t_node **a, t_node **b, int size);
void	size_3_max_first(t_node **a, t_node **b, int max, int min);
void	exception_size_5a(t_node **a, t_node **b, int size);
void	sort_size_5a(t_node **a, t_node **b, int size);

/*
** sort b to a.c
*/
void	sort_b_to_a(int size, t_node **a, t_node **b, int *flag);
void	rotate_push_a(t_node **a, t_node **b, t_call *call);
void	reverse_rotate_ra(t_node **a, t_node **b, t_call *call);
void	reverse_rotate_rb(t_node **a, t_node **b, t_call *call);
int		exceptions_b_to_a(int size, t_node **a, t_node **b);

/*
** exception b to a
*/
void	exception_size_under_3b(t_node **a, t_node **b, int size);
void	exception_size_5b(t_node **a, t_node **b, int size);
void	sort_size_5b(t_node **a, t_node **b, int size);

/*
** operations
*/
void	swap_ab(t_node **node, int stack);
void	swap_ss(t_node **a, t_node **b, int stack);
void	push_ab(t_node **dest, t_node **src, int stack);
void	rotate_ab(t_node **node, int stack);
void	rotate_rr(t_node **a, t_node **b, int stack);
void	rev_rotate_ab(t_node **node, int stack);
void	rotate_rrr(t_node **a, t_node **b, int stack);

/*
** stack sorted
*/
int		check_sorted(t_node **node);
int		check_sorted_with_size(t_node **node, int size);
int		check_sorted_descending(t_node **node, int size);

/*
** max min
*/
int		get_max(int size, t_node **node);
int		get_min(int size, t_node **node);

/*
** free
*/
void	free_node(t_node *node);
void	free_stack(t_node *a, t_node *b);

/*
** pivot
*/
void	set_pivots(t_node **node, int size, t_call *call);
void	get_big_pivot(t_node **node, int size, t_call *call);
void	get_small_pivot(t_node **node, int size, t_call *call);
int		*node_in_tab_sort(t_node **a, int size);
int		*sort_tab(int *tab, int size);

/*
** stack size five
*/
void	sort_five(int size, t_node **a, t_node **b);
int		get_mid_value_in_five(t_node **a, int size);
int		sort_tab_get_mid(int *tab, int size);

/*
** stack size three
*/
void	sort_three(int size, t_node **a);
void	node_3_min_first(t_node **a, int max);
void	node_3_min_mid(t_node **a, int max);
void	node_3_min_last(t_node **a, int max);

/*
** stack size two
*/
void	sort_two(t_node **a, t_node **b, int stack);

/*
** void	set_pivots_a(t_node **node, int size, t_call *call);
** void	set_pivots_b(t_node **node, int size, t_call *call);
** void	get_pivot(t_node **node, int size, t_call *call);
** void	rra_rrb_rrr_a(t_node **a, t_node **b, t_call *call, int *flag);
** void	rra_rrb_rrr_b(t_node **a, t_node **b, t_call *call);
** void	under_node_3_a(t_node **a, t_node **b, int size);
*/

#endif
