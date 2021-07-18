#include "../includes/push_swap.h"

void		sort_three(int size, t_node **a)
{
	int	max;
	int	min;
	int	last;
	
	max = get_max(size, a);
	min = get_min(size, a);
	last = get_last_value(a);
	if ((*a)->next->value == min)
	{
		if ((*a)->value == max)
			rotate_ab(a, A);
		else
			swap_ab(a, A);
	}
	else if ((*a)->value == min)
	{
		swap_ab(a, A);
		rotate_ab(a, A);
	}
	else if (last == min)
	{
		if ((*a)->value == max)
			swap_ab(a, A);
		rev_rotate_ab(a, A);
	}
}