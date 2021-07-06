#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_node{
    int value;
    struct s_node *prev;
    struct s_node *next;
}				t_node;

typedef struct s_info {
	int		i;
	int		j;
	char	**tmp;
	long	arg;
	int		listsize;
	int		ra;
	int		pb;
	t_node	*stack_a;
	t_node	*stack_b;
}				t_info;

void	ft_init(t_info *info);
void	create_stack(t_info *info, char **av);
int		check_double(char **s1, char *s2);
int		count_arg(char *str);
void	value_check(char *str, t_info *info);

void	print_node_a(t_node *node);
// void	print_node_a(t_node *node, t_info *info);
void	print_node_b(t_node *node);
void	print_node(t_node *node);

t_node	*creat_node();
void	insert_node(t_node **node, int value);
void	find_double(t_node *node, int value);
void	swap_ab(t_node **node);
void	swap_ss(t_node **a, t_node **b);
void	push_ab(t_node **dest, t_node **src);
void	rotate_ab(t_node **node);
void	rotate_rr(t_node **a, t_node **b);
void	rev_rotate_ab(t_node **node);
void	rotate_rrr(t_node **a, t_node **b);

int		check_order(t_node **node);
void	sort_a_to_b(t_node **a, t_node **b, t_info *info);
// void	set_in_order_two(t_node **n1);
// void	set_in_order_three(t_node **a, t_info *info);

#endif
