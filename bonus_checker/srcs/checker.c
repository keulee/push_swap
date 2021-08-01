#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_info	info;
	char	*buf;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);
	while ((get_next_line(0, &buf)) > 0)
	{
		printf("checker base done\n");
	}
	free_stack(info.stack_a, info.stack_b);

	return (0);
}