#include "../includes/checker.h"

void	checker_process(char *buf, t_node **a, t_node **b)
{
	if (!ft_strcmp("pa", buf))
		push_ab(a, b, 3);
	else if (!ft_strcmp("pb", buf))
		push_ab(b, a, 3);
	else if (!ft_strcmp("sa", buf))
		swap_ab(a, 3);
	else if (!ft_strcmp("sb", buf))
		swap_ab(b, 3);
	else if (!ft_strcmp("ss", buf))
		swap_ss(a, b, 3);
	else if (!ft_strcmp("ra", buf))
		rotate_ab(a, 3);
	else if (!ft_strcmp("rb", buf))
		rotate_ab(b, 3);
	else if (!ft_strcmp("rr", buf))
		rotate_rr(a, b, 3);
	else if (!ft_strcmp("rra", buf))
		rev_rotate_ab(a, 3);
	else if (!ft_strcmp("rrb", buf))
		rev_rotate_ab(b, 3);
	else if (!ft_strcmp("rrr", buf))
		rotate_rrr(a, b, 3);
	else
		ft_exit_msg("ERROR");
}
