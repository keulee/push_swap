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
		if (!ft_strcmp("pa", buf))
		{
			push_ab(&info.stack_a, &info.stack_b, 3);
			free(buf);
		}
		else if (!ft_strcmp("pb", buf))
		{
			push_ab(&info.stack_b, &info.stack_a, 3);
			free(buf);
		}
		else if (!ft_strcmp("sa", buf))
		{
			swap_ab(&info.stack_a, 3);
			free(buf);
		}
		else if (!ft_strcmp("sb", buf))
		{
			swap_ab(&info.stack_b, 3);
			free(buf);
		}
		else if (!ft_strcmp("ss", buf))
		{
			swap_ss(&info.stack_a, &info.stack_b, 3);
			free(buf);
		}
		else if (!ft_strcmp("ra", buf))
		{	
			rotate_ab(&info.stack_a, 3);
			free(buf);
		}
		else if (!ft_strcmp("rb", buf))
		{
			rotate_ab(&info.stack_b, 3);
			free(buf);
		}
		else if (!ft_strcmp("rr", buf))
		{
			rotate_rr(&info.stack_a, &info.stack_b, 3);
			free(buf);
		}
		else if (!ft_strcmp("rra", buf))
		{
			rev_rotate_ab(&info.stack_a, 3);
			free(buf);
		}
		else if (!ft_strcmp("rrb", buf))
		{	
			rev_rotate_ab(&info.stack_b, 3);
			free(buf);
		}
		else if (!ft_strcmp("rrr", buf))
		{	
			rotate_rrr(&info.stack_a, &info.stack_b, 3);
			free(buf);
		}
		else
			ft_exit_msg("ERROR");
	}
	free(buf);
	if (check_sorted(&info.stack_a) && info.stack_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(info.stack_a, info.stack_b);
	return (EXIT_SUCCESS);
}