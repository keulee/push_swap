#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_info	*info;
	char	*line;
	int		res;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);
	
	printf("checker base done\n");

	return (0);
}