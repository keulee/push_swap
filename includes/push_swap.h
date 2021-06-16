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

// typedef struct s_list{
// 	t_node	*tail;
// 	int		count;
// }				t_list;

typedef struct s_info {
	char	**tmp;
	long	arg;
	int		listsize;
	t_node	*head;
	// t_list	*list;
}				t_info;

void	ft_init(t_info *info);
int		check_double(char **s1, char *s2);
int		count_arg(char *str);
void	value_check(char *str, t_info *info);
// void	init_list(t_list *list);
// void	add_value(t_list *list, int count, int value);
void	insert_value(t_node **node, int value);
void	find_double(t_node *node, int value);
void		print_node(t_node *node, t_info *info);

#endif
