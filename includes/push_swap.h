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
    int value;
    struct s_node *prev;
    struct s_node *next;
}				t_node;

typedef struct s_call{
	int		ra;
	int		pb;
	int		rb;
	int		pa;
	int		pivot;
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

void	ft_init(t_info *info);
void	call_init(t_call *call);

void	create_stack(t_info *info, char **av);
int		check_double(char **s1, char *s2);
int		count_arg(char *str);
void	value_check(char *str, t_info *info);

void	print_node_a(t_node *node);
void	print_node_b(t_node *node);
void	print_node(t_node *node);

int		get_listsize(t_node **a);
void	insert_node(t_node **node, int value);
void	find_double(t_node *node, int value);
void	swap_ab(t_node **node, int stack);
void	swap_ss(t_node **a, t_node **b, int stack);
void	push_ab(t_node **dest, t_node **src, int stack);
void	rotate_ab(t_node **node, int stack);
void	rotate_rr(t_node **a, t_node **b, int stack);
void	rev_rotate_ab(t_node **node, int stack);
void	rotate_rrr(t_node **a, t_node **b, int stack);

int		check_sorted(t_node **node);
void	sort_a_to_b(int size, t_node **a, t_node **b);
void	sort_b_to_a(int size, t_node **a, t_node **b);

void	free_node(t_node *node);
void	free_stack(t_node *a, t_node *b);

int		get_max(int size, t_node **node);
int		get_min(int size, t_node **node);

void	sort_two(t_node **node, int stack);
void	sort_three(int size, t_node **a);
void	sort_five(int size, t_node **a, t_node **b);
int		get_last_value(t_node **node);
int		get_mid_value_in_five(t_node **a, int size);
int		sort_tab_get_mid(int *tab, int size);

int     *node_in_tab_sort(t_node **a, int size);
int		*sort_tab(int *tab, int size);
void     get_pivots_in_a(t_node **node, int size, t_call *call);
void     get_pivots_in_b(t_node **node, int size, t_call *call);

int		exceptions_under_3_a(int size, t_node **a, t_node **b, t_call *call);

int		check_sorted_descending(t_node **node, int size);
int		check_sorted_with_size(t_node **node, int size);
int     exceptions_under_3_b(int size, t_node **a, t_node **b, t_call *call);

void	set_pivots(t_node **node, int size, t_call *call);
void	get_pivot(t_node **node, int size, t_call *call);
void	get_big_pivot(t_node **node, int size, t_call *call);
void	get_small_pivot(t_node **node, int size, t_call *call);

#endif
