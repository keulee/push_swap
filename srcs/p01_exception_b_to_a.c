#include "../includes/push_swap.h"

void	exception_size_under_3b(t_node **a, t_node **b, int size)
{
	int	max;
	int	min;

	if (size == 2)
	{
		sort_two(a, b, B);
		return ;
	}
	else if (size == 3)
	{
		push_ab(a, b, A);
		push_ab(a, b, A);
		push_ab(a, b, A);
		max = get_max(3, a);
		min = get_min(3, a);
		if (check_sorted_with_size(a, 3))
			return ;
		else if ((*a)->next->next->value == max)
		{
			swap_ab(a, A);
			return ;
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
		return ;
	}
}

void	exception_size_5b(t_node **a, t_node **b, int size)
{
	int	max;
	int	min;
	int	mid = get_mid_value_in_five(b, size);
	int	pa = 0;
	int	rb = 0;
	while (size--)
	{
		if ((*b)->value >= mid)
		{
			push_ab(a, b, A);
			pa++;
		}
		else if ((*b)->value < mid)
		{
			rotate_ab(b, B);
			rb++;
		}
		if (pa == 3)
			break ;
	}
	while (rb--)
		rev_rotate_ab(b, B);
	max = get_max(3, a);
	min = get_min(3, a);
	if (check_sorted_with_size(a, 3))
	{
		sort_two(a, b, B);
		return ;
	}
	else if ((*a)->next->next->value == max)
	{
		swap_ab(a, A);
		sort_two(a, b, B);
		return ;
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
	return ;
}