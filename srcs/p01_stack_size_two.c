#include "../includes/push_swap.h"

void	sort_two(t_node **a, t_node **b, int stack)
{
	if (stack == A)
	{
		if ((*a)->value > (*a)->next->value)
			swap_ab(a, A);
	}
	else if (stack == B)
	{
		if ((*b)->value < (*b)->next->value)
			swap_ab(b, B);
		push_ab(a, b, A);
		push_ab(a, b, A);
	}
}
