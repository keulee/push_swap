#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_info info;
	int i;

	i = 1;
	info.string = NULL;
	info.av_with_space = NULL;
	if (ac < 2)
		ft_exit_msg("ERROR: Argument not enough");
	else
	{
		while (i < ac)
		{
			// printf("av: %s\n", av[i]);
			info.av_with_space = ft_strjoin(av[i], " ");
			printf("%s\n", info.av_with_space);
			info.string = ft_strjoin(info.string, info.av_with_space);
			if (!info.string)
			{
				info.string = info.av_with_space;
				printf("str: %s\n", info.string);
				// free(info.av_with_space);
			}
			// free(info.av_with_space);
			i++;
		}
	}
	printf("%s\n", info.string);
	return (0);
}