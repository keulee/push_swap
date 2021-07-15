#include "../includes/push_swap.h"

void		sort_max_three(int size, t_node **a)
{
	long	max;
	long	min;
	long	last;
	
	max = get_max(size, a);
	min = get_min(size, a);
	last = get_last_value(a);
	// printf("max nbr : %ld\n", max);
	// if (size == 2)
	// {
	// 	if ((*a)->value == max)
	// 		swap_ab(a, A);
	// // }
	// else if (size == 3 && !check_sorted(a))
	// {
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