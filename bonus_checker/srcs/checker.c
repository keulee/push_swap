#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_info	info;
	char	*buf;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);
	// if (info.stack_a == NULL && info.stack_b == NULL) // case with <./checker ""> -> needed or not?
	// 	exit(0);
	while ((get_next_line(0, &buf)) > 0)
	{
		checker_process(buf, &info.stack_a, &info.stack_b);
		free(buf);
	}
	free(buf);
	if (check_sorted(&info.stack_a) && info.stack_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(info.stack_a, info.stack_b);
	return (EXIT_SUCCESS);
}