#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_info info;
	int i;

	info.string = NULL;
	info.av_with_space = NULL;
	if (ac < 2)
		ft_exit_msg("ERROR: Argument not enough");
	else
	{
		info.string = ft_strjoin(av[1], " ");
		i = 2;
		while (i < ac)
		{
			info.av_with_space = ft_strjoin(av[i], " ");
			info.string = ft_make_string(info.string, info.av_with_space);
			free(info.av_with_space);
			info.av_with_space = NULL;
			i++;
		}
	}
	printf("%s\n", info.string);
	free(info.string);
	return (EXIT_SUCCESS);
}