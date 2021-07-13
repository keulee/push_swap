#include "../includes/push_swap.h"

void	sort_max_five(int size, t_node **a, t_node **b)
{
	t_node *tmp;
	long	max;
	long	mid;
	long	min;

	tmp = *b;
	while (size != 3)
	{
		push_ab(b, a, B);
		size--;
	}
	if (size == 3)
	{
		sort_max_three(size, a);
		max = get_max(size, a);
		mid = get_mid_value(a);
		min = get_min(size, a);
		// printf("max value : %ld\n", max);
		// printf("mid value : %ld\n", mid);
		// printf("min value : %ld\n", min);
		// printf("b value : %d\n", (*b)->value);
		if ((*b)->value < min)
			push_ab(a, b, A);
		else if (min < (*b)->value && mid > (*b)->value)
		{
			rotate_ab(a, A);
			push_ab(a, b, A);
			rev_rotate_ab(a, A);
			// printf("here\n");

		}
		else if (mid < (*b)->value && max > (*b)->value)
		{
			rev_rotate_ab(a, A);
			push_ab(a, b, A);
			rotate_ab(a, A);
			rotate_ab(a, A);
			// printf("here\n");
		}
		else if (max < (*b)->value)
		{
			push_ab(a, b, A);
			rotate_ab(a, A);
			// printf("here\n");

		}
		// if ((*a)->value > (*b)->value)
		// 	push_ab(a, b, A);
		// else if ((*b)->value > last)
		// {
		// 	push_ab(a, b, A);
		// 	rotate_ab(a, A);
		// }
		// else
		// {
		// 	if ((*a)->next->value < (*b)->value)
		// 	{
		// 		rev_rotate_ab(a, A);
		// 		push_ab(a, b, A);
		// 		rotate_ab(a, A);
		// 	}
		// 	else
		// 	{
		// 		rotate_ab(a, A);
		// 		push_ab(a, b, A);
		// 		rev_rotate_ab(a, A);
		// 	}
		// }
	}
}