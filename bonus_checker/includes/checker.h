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

/*
** init
*/
void	ft_init(t_info *info);
void	call_init(t_call *call);

#endif