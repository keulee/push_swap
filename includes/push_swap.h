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
	char	**tmp;
	int		arg;
	t_node	*head;
}				t_info;

void	ft_init(t_info *info);
int		check_double(char **s1, char *s2);
int		count_arg(char *str);
void	value_check(char *str, int neg);


#endif
