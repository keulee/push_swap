#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_info	*info;
	char	*buf;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);
	whlie(get_next_line(0, &buf) > 0)
	{
		
	}

	printf("checker base done\n");

	return (0);
}