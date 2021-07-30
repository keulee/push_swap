#include "../includes/push_swap.h"

void	exception_size3_node3(t_node **a)
{
	if (check_sorted(a))
		return ;
	else
		sort_three(3, a);
	return ;
}

void	exception_size_3(t_node **a, t_node **b, int size)
{
	int	max;
	int	min;

	max = get_max(size, a);
	min = get_min(size, a);
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

void	exception_size_5(t_node **a, t_node **b, int size)
{
	int	mid;
	int	pb;
	int	ra;

	mid = get_mid_value_in_five(a, size);
	pb = 0;
	ra = 0;
	if (check_sorted_with_size(a, 5))
		return ;
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
	exception_size_3(a, b, 3);
	sort_two(a, b, B);
	return ;
}
