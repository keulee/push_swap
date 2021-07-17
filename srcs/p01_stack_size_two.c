#include "../includes/push_swap.h"

void	sort_two(t_node **node, int stack)
{
	if (stack == A)
	{
		if ((*node)->value > (*node)->next->value)
			swap_ab(node, A);
	}
	else if (stack == B)
	{
		if ((*node)->value < (*node)->next->value)
			swap_ab(node, B);
	}
}