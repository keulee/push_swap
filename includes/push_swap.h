#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_info {
	char	**tmp;
	//char	*av_with_space;
	//char	*string;
	//char	**arg;
	//int		count;
	//char	**check;
}				t_info;

void	ft_init(t_info *info);
int		check_double(char **s1, char *s2);
int		count_arg(char *str);


#endif
