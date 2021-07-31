#include "../includes/push_swap.h"

void	sort_b_to_a(int size, t_node **a, t_node **b, int *flag)
{
	t_call	call;

	(*flag)++;
	if (exceptions_under_5_b(size, a, b))
	{
		return ;
	}
	call_init(&call);
	set_pivots(b, size, &call);
	while (size--)
		rotate_push_a(a, b, &call);
	sort_a_to_b((call.pa - call.ra), a, b, flag);
	if (call.ra >= call.rb)
		reverse_rotate_ra(a, b, &call);
	else
		reverse_rotate_rb(a, b, &call);
	sort_a_to_b(call.ra, a, b, flag);
	sort_b_to_a(call.rb, a, b, flag);
}

void	rotate_push_a(t_node **a, t_node **b, t_call *call)
{
	if ((*b)->value < call->small_p)
	{
		call->rb++;
		rotate_ab(b, B);
	}
	else if ((*b)->value >= call->small_p)
	{
		call->pa++;
		push_ab(a, b, A);
		if ((*a)->value < call->big_p)
		{
			call->ra++;
			rotate_ab(a, A);
		}
	}
}

void	reverse_rotate_ra(t_node **a, t_node **b, t_call *call)
{
	int	rrr;
	int	rra;

	rrr = call->rb;
	rra = call->ra - rrr;
	while (rrr--)
		rotate_rrr(a, b, AB);
	while (rra--)
		rev_rotate_ab(a, A);
}

void	reverse_rotate_rb(t_node **a, t_node **b, t_call *call)
{
	int	rrr;
	int	rrb;

	rrr = call->ra;
	rrb = call->rb - rrr;
	while (rrr--)
		rotate_rrr(a, b, AB);
	while (rrb--)
		rev_rotate_ab(b, B);
}

int	exceptions_under_5_b(int size, t_node **a, t_node **b)
{

	if (check_sorted_descending(b, size))
	{
		while (size--)
			push_ab(a, b, A);
		return (1);
	}
	else if (size <= 3)
	{
		exception_size_under_3b(a, b, size);
		return (1);
	}
	else if (size == 5)
	{
		exception_size_5b(a, b, size);
		return (1);
	}
	// else if (size == 2)
	// {
	// 	sort_two(a, b, B);
	// 	return (1);
	// }
	// else if (size == 3)
	// {
	// 	push_ab(a, b, A);
	// 	push_ab(a, b, A);
	// 	push_ab(a, b, A);
	// 	max = get_max(3, a);
	// 	min = get_min(3, a);
	// 	if (check_sorted_with_size(a, 3))
	// 	{
	// 		return (1);
	// 	}
	// 	else if ((*a)->next->next->value == max)
	// 	{
	// 		swap_ab(a, A);
	// 		return (1);
	// 	}
	// 	if ((*a)->value == max)
	// 		swap_ab(a, A);
	// 	if ((*a)->value == min)
	// 	{
	// 		rotate_ab(a, A);
	// 		swap_ab(a, A);
	// 		rev_rotate_ab(a, A);
	// 	}
	// 	else
	// 	{
	// 		push_ab(b, a, B);
	// 		swap_ab(a, A);
	// 		push_ab(a, b, A);
	// 		swap_ab(a, A);
	// 	}
	// 	return (1);
	// }
	// else if (size == 5)
	// {
		// int	mid = get_mid_value_in_five(b, size);
		// int	pa = 0;
		// int	rb = 0;
		// while (size--)
		// {
		// 	if ((*b)->value >= mid)
		// 	{
		// 		push_ab(a, b, A);
		// 		pa++;
		// 	}
		// 	else if ((*b)->value < mid)
		// 	{
		// 		rotate_ab(b, B);
		// 		rb++;
		// 	}
		// 	if (pa == 3)
		// 		break ;
		// }
		// while (rb--)
		// 	rev_rotate_ab(b, B);
		// max = get_max(3, a);
		// min = get_min(3, a);
		// if (check_sorted_with_size(a, 3))
		// {
		// 	sort_two(a, b, B);
		// 	return (1);
		// }
		// else if ((*a)->next->next->value == max)
		// {
		// 	swap_ab(a, A);
		// 	sort_two(a, b, B);
		// 	return (1);
		// }
		// if ((*a)->value == max)
		// 	swap_ab(a, A);
		// if ((*a)->value == min)
		// {
		// 	rotate_ab(a, A);
		// 	swap_ab(a, A);
		// 	rev_rotate_ab(a, A);
		// }
		// else
		// {
		// 	push_ab(b, a, B);
		// 	swap_ab(a, A);
		// 	push_ab(a, b, A);
		// 	swap_ab(a, A);
		// }
		// sort_two(a, b, B);
		// return (1);
	// }
	return (0);
}
