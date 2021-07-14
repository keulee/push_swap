#include "../includes/push_swap.h"

void	sort_max_five(int size, t_node **a, t_node **b)
{
	long	max;
	long	mid;
	long	min;

	max = get_max(size, a);
	min = get_min(size, a);
	if (size == 2)
	{
		if ((*a)->value == max)
			swap_ab(a, A);
		return ;
	}
	while (size != 3)
	{
		push_ab(b, a, B);
		size--;
	}
	if (size == 3)
	{
		sort_max_three(size, a);
		if (!*b)
			return ;
		max = get_max(size, a);
		mid = get_mid_value(a);
		min = get_min(size, a);
		if ((*b)->next != NULL)
		{	
			if ((*b)->value < (*b)->next->value)
				swap_ab(b, B);
		}
		// printf("max value : %ld\n", max);
		// printf("mid value : %ld\n", mid);
		// printf("min value : %ld\n", min);
		// printf("b value : %d\n", (*b)->value);
		while (*b)
		{
			if ((*b)->value < min)
				push_ab(a, b, A);
			else if (min < (*b)->value && mid > (*b)->value)
			{
				rotate_ab(a, A);
				push_ab(a, b, A);
				rev_rotate_ab(a, A);
				// printf("here1\n");

			}
			else if (mid < (*b)->value && max > (*b)->value)
			{
				rev_rotate_ab(a, A);
				push_ab(a, b, A);
				if (*b && mid < (*b)->value)
				{
					push_ab(a, b, A);
					rotate_ab(a, A);
				}
				rotate_ab(a, A);
				rotate_ab(a, A);
				// printf("here2\n");
			}
			else if (max < (*b)->value)
			{
				push_ab(a, b, A);
				if (*b && (*b)->value < max && (*b)->value > mid)
				{
					rev_rotate_ab(a, A);
					push_ab(a, b, A);
					rotate_ab(a, A);
					rotate_ab(a, A);
				}
				rotate_ab(a, A);
				// printf("here3\n");
			}
		}
	}
}