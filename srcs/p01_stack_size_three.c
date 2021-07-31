#include "../includes/push_swap.h"

void	sort_three(int size, t_node **a)
{
	int	max;
	int	min;

	max = get_max(size, a);
	min = get_min(size, a);
	if ((*a)->value == min)
		node_3_min_first(a, max);
	else if ((*a)->next->value == min)
		node_3_min_mid(a, max);
	else if ((*a)->next->next->value == min)
		node_3_min_last(a, max);
}

void	node_3_min_first(t_node **a, int max)
{
	if ((*a)->next->value == max)
	{
		rev_rotate_ab(a, A);
		swap_ab(a, A);
	}
}

void	node_3_min_mid(t_node **a, int max)
{
	if ((*a)->value == max)
		rotate_ab(a, A);
	else
		swap_ab(a, A);
}

void	node_3_min_last(t_node **a, int max)
{
	if ((*a)->value == max)
		swap_ab(a, A);
	rev_rotate_ab(a, A);
}
