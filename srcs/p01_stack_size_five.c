#include "../includes/push_swap.h"

void	sort_five(int size, t_node **a, t_node **b)
{
	int		max;
	int		mid;
	int		min;
	t_call	call;

	max = get_max(size, a);
	min = get_min(size, a);
	mid = (max + min) / 2;
	call_init(&call);
	printf("max value : %d\n", max);
	printf("mid value : %d\n", mid);
	printf("min value : %d\n", min);
	while (size)
	{
		if ((*a)->value <= mid)
		{
			push_ab(b, a, B);
			call.pb++;
		}
		else
		{
			rotate_ab(a, A);
			call.ra++;
		}
		size--;
	}
	if (call.ra == 2)
		sort_two(a, A);
	else
		sort_three(call.ra, a);
	if (call.pb == 2)
	{
		sort_two(b, B);
		while (call.pb--)
			push_ab(a, b, A);
	}
	else
	{
		if (!check_sorted(b))
			sort_three(3, b);
		swap_ab(b, B);
		rev_rotate_ab(b, B);
		while (call.pb--)
			push_ab(a, b, A);
	}


	




	// if (size == 3)
	// {
	// 	sort_three(size, a);
	// 	if (!*b)
	// 		return ;
	// 	max = get_max(size, a);
	// 	mid = get_mid_value(a);
	// 	min = get_min(size, a);
	// 	if ((*b)->next != NULL)
	// 	{	
	// 		if ((*b)->value < (*b)->next->value)
	// 			swap_ab(b, B);
	// 	}
	// 	// printf("max value : %ld\n", max);
	// 	// printf("mid value : %ld\n", mid);
	// 	// printf("min value : %ld\n", min);
	// 	// printf("b value : %d\n", (*b)->value);
	// 	while (*b)
	// 	{
	// 		if ((*b)->value < min)
	// 			push_ab(a, b, A);
	// 		else if (min < (*b)->value && mid > (*b)->value)
	// 		{
	// 			rotate_ab(a, A);
	// 			push_ab(a, b, A);
	// 			rev_rotate_ab(a, A);
	// 			// printf("here1\n");

	// 		}
	// 		else if (mid < (*b)->value && max > (*b)->value)
	// 		{
	// 			rev_rotate_ab(a, A);
	// 			push_ab(a, b, A);
	// 			if (*b && mid < (*b)->value)
	// 			{
	// 				push_ab(a, b, A);
	// 				rotate_ab(a, A);
	// 			}
	// 			rotate_ab(a, A);
	// 			rotate_ab(a, A);
	// 			// printf("here2\n");
	// 		}
	// 		else if (max < (*b)->value)
	// 		{
	// 			push_ab(a, b, A);
	// 			if (*b && (*b)->value < max && (*b)->value > mid)
	// 			{
	// 				rev_rotate_ab(a, A);
	// 				push_ab(a, b, A);
	// 				rotate_ab(a, A);
	// 				rotate_ab(a, A);
	// 			}
	// 			rotate_ab(a, A);
	// 			// printf("here3\n");
	// 		}
	// 	}
	// }
}