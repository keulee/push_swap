#include "../includes/push_swap.h"

void	sort_a_to_b(int size, t_node **a, t_node **b, int *flag)
{
	t_call call;

    // printf("==============in a to b================\n");
    // printf("size in a: %d\n", size);
	// printf("flag : %d\n", (*flag));
	if (exceptions_under_5_a(size, a, b, flag))
	{
		return ;
	}
	call_init(&call);
	set_pivots(a, size, &call);
	// set_pivots_a(a, size, &call);
	// printf("ra: %d\n", call.ra);
	// printf("rb: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	// printf("big pivot: %d\n", call.big_p);
	// printf("small pivot: %d\n", call.small_p);
	while (size--)
	{
		if ((*a)->value >= call.big_p)
		{
			call.ra++;
			rotate_ab(a, A);
		}
		else if ((*a)->value < call.big_p)
		{
			call.pb++;
			push_ab(b, a, B);
			if ((*b)->value >= call.small_p)
			{
				call.rb++;
				rotate_ab(b, B);
			}
		}
	}
	// printf("ra == next size a to b: %d\n", call.ra);
	// printf("rb == next size b to a: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	rra_rrb_rrr_a(a, b, &call, flag);
	// printf("ra == next size a to b: %d\n", call.ra);
	// printf("rb == next size b to a: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	// print_node_a(*a);
	// print_node_a(*b);
	sort_a_to_b(call.ra, a, b, flag);
	// print_node_a(*a);
	// print_node_a(*b);
	sort_b_to_a(call.rb, a, b, flag);
	// printf("pb - rb: %d\n", call.pb - call.rb);
	sort_b_to_a(call.pb - call.rb, a, b, flag);
}

void	rra_rrb_rrr_a(t_node **a, t_node **b, t_call *call, int *flag)
{
	int rrr;
	int	rra;
	int rrb;

	if (call->ra >= call->rb)
	{
		rrr = call->rb;
		rra = call->ra - rrr;
		if ((*flag) > 0)
		{
			while (rrr--)
				rotate_rrr(a, b, AB);
			while (rra--)
				rev_rotate_ab(a, A);

		}
		else
		{
			while (rrr--)
				rev_rotate_ab(b, B);
		}
	}
	else
	{
		rrr = call->ra;
		rrb = call->rb - rrr;
		if ((*flag) > 0)
		{
			while (rrr--)
				rotate_rrr(a, b, AB);
			while (rrb--)
				rev_rotate_ab(b, B);
		}
		else
		{
			rrr = call->rb;
			while (rrr--)
				rev_rotate_ab(b, B);
		}
	}
}

int		exceptions_under_5_a(int size, t_node **a, t_node **b, int *flag)
{
	int	max;
	int	min;
	
	(void)flag;
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
	// else if (size == 3 && get_listsize(a) == 3)
	// {
	// 	if (check_sorted(a))
	// 		return (1);
	// 	else
	// 		sort_three(3, a);
	// 	return (1);
	// }
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
	// else if (size == 5)
	// {
	// 	int mid = get_mid_value_in_five(a, size);
	// 	int pb = 0;
	// 	int ra = 0;
	// 	if (check_sorted_with_size(a, 5))
	// 		return (1);
	// 	while (size--)
	// 	{
	// 		if ((*a)->value < mid)
	// 		{
	// 			push_ab(b, a, B);
	// 			pb++;
	// 		}
	// 		else if ((*a)->value >= mid)
	// 		{
	// 			rotate_ab(a, A);
	// 			ra++;
	// 		}
	// 		if (pb == 2)
	// 			break ;
	// 	}
	// 	while (ra--)
	// 		rev_rotate_ab(a, A);
	// 	sort_a_to_b(3, a, b, flag);
	// 	sort_two(a, b, B);
	// 	return (1);
	// }
	return (0);
}
