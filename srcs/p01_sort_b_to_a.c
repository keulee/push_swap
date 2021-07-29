#include "../includes/push_swap.h"

void	sort_b_to_a(int size, t_node **a, t_node **b, int *flag)
{
	t_call call;

	(*flag)++;
	// printf("flag : %d\n", (*flag));
	// printf("==============in b to a================\n");
	// printf("size in b: %d\n", size);
	if (exceptions_under_5_b(size, a, b, flag))
	{
		return ;
	}
	call_init(&call);
	set_pivots(b, size, &call);
	// set_pivots_b(b, size, &call);
	// printf("big pivot: %d\n", call.big_p);
	// printf("small pivot: %d\n", call.small_p);
	while (size--)
	{
		if ((*b)->value < call.small_p)
		{
			call.rb++;
			rotate_ab(b, B);
		}
		else if ((*b)->value >= call.small_p)
		{
			call.pa++;
			push_ab(a, b, A);
			if ((*a)->value < call.big_p)
			{
				call.ra++;
				rotate_ab(a, A);
			}
		}
	}
	// printf("raa: %d\n", call.ra);
	// printf("rb: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	// printf("pa-ra: %d\n", call.pa - call.ra);
	// print_node_a(*a);
	// print_node_a(*b);
	sort_a_to_b((call.pa - call.ra), a, b, flag);
	rra_rrb_rrr_b(a, b, &call);
	// rra_rrb_rrr_b(a, b, &call);
	// printf("ra == next size a to b: %d\n", call.ra);
	// printf("rb == next size b to a: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	// print_node_a(*a);
	// print_node_a(*b);
	sort_a_to_b(call.ra, a, b, flag);
	sort_b_to_a(call.rb, a, b, flag);
}

void	rra_rrb_rrr_b(t_node **a, t_node **b, t_call *call)
{
	int rrr;
	int rra;
	int rrb;

	if (call->ra >= call->rb)
	{
		rrr = call->rb;
		rra = call->ra - rrr;
		while (rrr--)
			rotate_rrr(a, b, AB);
		while (rra--)
			rev_rotate_ab(a, A);
	}
	else
	{
		rrr = call->ra;
		rrb = call->rb - rrr;
		while (rrr--)
			rotate_rrr(a, b, AB);
		while (rrb--)
			rev_rotate_ab(b, B);
	}
}


int	exceptions_under_5_b(int size, t_node **a, t_node **b, int *flag)
{
	int max;
	int min;

	max = get_max(size, b);
	min = get_min(size, b);
	if (size == 2)
	{
		sort_two(a, b, B);
		return (1);
	}
	else if (size == 3)
	{
		push_ab(a, b, A);
		push_ab(a, b, A);
		push_ab(a, b, A);
		sort_a_to_b(3, a, b, flag);
		return (1);
	}
	// else if (size == 5)
	// {
	// 	int mid = get_mid_value_in_five(b, size);
	// 	int pa = 0;
	// 	int rb = 0;
	// 	while (size--)
	// 	{
	// 		if ((*b)->value >= mid)
	// 		{
	// 			push_ab(a, b, A);
	// 			pa++;
	// 		}
	// 		else if ((*a)->value < mid)
	// 		{
	// 			rotate_ab(b, B);
	// 			rb++;
	// 		}
	// 		if (pa == 3)
	// 			break ;
	// 	}
	// 	while (rb--)
	// 		rev_rotate_ab(b, B);
	// 	sort_a_to_b(3, a, b, flag);
	// 	sort_two(a, b, B);
	// 	return (1);
	// }
	else if (check_sorted_descending(b, size))
	{
		while (size--)
			push_ab(a, b, A);
		return (1);
	}
	return (0);
}