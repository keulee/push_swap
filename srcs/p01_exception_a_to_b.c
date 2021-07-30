#include "../includes/push_swap.h"

int		exceptions_under_5_a(int size, t_node **a, t_node **b)
{
	int	max;
	int	min;
	
	max = get_max(size, a);
	min = get_min(size, a);
	if (check_sorted(a))
		return (1);
	if (size == 1)
		return (1);
	else if (size == 2)
	{
		sort_two(a, b, A);
		return (1);
	}
	else if (size == 3 && get_listsize(a) == 3)
	{
		if (check_sorted(a))
			return (1);
		else
			sort_three(3, a);
		return (1);
	}
	else if (size == 3)
	{
		if (check_sorted_with_size(a, 3))
			return (1);
		else if ((*a)->next->next->value == max)
		{
			swap_ab(a, A);
			return (1);
		}
		if ((*a)->value == max)
			swap_ab(a, A);
		if ((*a)->value == min)
		{
			rotate_ab(a, A);
			swap_ab(a, A);
			rev_rotate_ab(a, A);
		}
		else
		{
			push_ab(b, a, B);
			swap_ab(a, A);
			push_ab(a, b, A);
			swap_ab(a, A);
		}
		return (1);
	}
	else if (size == 5)
	{
		int mid = get_mid_value_in_five(a, size);
		int pb = 0;
		int ra = 0;
		if (check_sorted_with_size(a, 5))
			return (1);
		while (size--)
		{
			if ((*a)->value < mid)
			{
				push_ab(b, a, B);
				pb++;
			}
			else if ((*a)->value >= mid)
			{
				rotate_ab(a, A);
				ra++;
			}
			if (pb == 2)
				break ;
		}
		while (ra--)
			rev_rotate_ab(a, A);
		max = get_max(3, a);
		min = get_min(3, a);
		if (check_sorted_with_size(a, 3))
		{
			sort_two(a, b, B);
			return (1);
		}
		else if ((*a)->next->next->value == max)
		{
			swap_ab(a, A);
			sort_two(a, b, B);
			return (1);
		}
		if ((*a)->value == max)
			swap_ab(a, A);
		if ((*a)->value == min)
		{
			rotate_ab(a, A);
			swap_ab(a, A);
			rev_rotate_ab(a, A);
		}
		else
		{
			push_ab(b, a, B);
			swap_ab(a, A);
			push_ab(a, b, A);
			swap_ab(a, A);
		}
		sort_two(a, b, B);
		return (1);
	}
	return (0);
}