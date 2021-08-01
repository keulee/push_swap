#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../../libft/libft.h"

# define BUFFER_SIZE 1

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
** checker process
*/
void	checker_process(char *buf, t_node **a, t_node **b);

/*
** GNL
*/
int		get_next_line(int fd, char **line);

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
** free
*/
void	free_node(t_node *node);
void	free_stack(t_node *a, t_node *b);

#endif