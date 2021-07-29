#include "../includes/push_swap.h"

void	sort_three(int size, t_node **a)
{
	int	max;
	int	min;

	max = get_max(size, a);
	min = get_min(size, a);
	if ((*a)->value == min)
	{
		if ((*a)->next->value == max)
		{
			rev_rotate_ab(a, A);
			swap_ab(a, A);
		}
	}
	else if ((*a)->next->value == min)
	{
		if ((*a)->value == max)
			rotate_ab(a, A);
		else
			swap_ab(a, A);
	}
	else if ((*a)->next->next->value == min)
	{
		if ((*a)->value == max)
			swap_ab(a, A);
		rev_rotate_ab(a, A);
	}
}
