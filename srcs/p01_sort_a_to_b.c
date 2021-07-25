#include "../includes/push_swap.h"

void	sort_a_to_b(int size, t_node **a, t_node **b)
{
	t_call call;


    // printf("==============in a to b================\n");
    // printf("size in a: %d\n", size);
	call_init(&call);
	if (exceptions_under_3_a(size, a, &call))
	{
		return ;
	}
	set_pivots(a, size, &call);
	// printf("ra: %d\n", call.ra);
	// printf("rb: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	// printf("pivot: %d\n", call.pivot);
	// printf("big pivot: %d\n", call.big_p);
	// printf("small pivot: %d\n", call.small_p);
	while (size--)
	{
		if ((*a)->value >= call.big_p)
		{
			rotate_ab(a, A);
			call.ra++;
		}
		else if ((*a)->value < call.big_p)
		{
			push_ab(b, a, B);
			call.pb++;
			if ((*b)->value >= call.small_p)
			{
				rotate_ab(b, B);
				call.rb++;
			}
		}
	}
	int rrr = 0;
	int	ra = 0;
	int rb = 0;;
	if (call.ra >= call.rb)
	{
		rrr = call.rb;
		ra = call.ra - rrr;
		while (rrr--)
			rotate_rrr(a, b, AB);
		while (ra--)
			rev_rotate_ab(a, A);
	}
	else
	{
		rrr = call.ra;
		rb = call.rb - rrr;
		while (rrr--)
			rotate_rrr(a, b, AB);
		while (rb--)
			rev_rotate_ab(b, B);
	}
	// printf("ra == next size a to b: %d\n", call.ra);
	// printf("rb == next size b to a: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	// print_node_a(*a);
	// print_node_a(*b);
	sort_a_to_b(call.ra, a, b);
	// print_node_a(*a);
	// print_node_a(*b);
	sort_b_to_a(call.rb, a, b);
	sort_b_to_a(call.pb - call.rb, a, b);
}

int		exceptions_under_3_a(int size, t_node **a, t_call *call)
{
	int	max;
	int	min;
	
	(void)call;
	max = get_max(size, a);
	min = get_min(size, a);
	if (check_sorted_with_size(a, size))
		return (1);
	else if (size == 1)
		return (1);
	else if (size == 2)
	{
		sort_two(a, A);
		return (1);
	}
	else if (size == 3)
	{
		if ((*a)->next->value == min)
		{
			if ((*a)->value == max)
			// {
				rotate_ab(a, A);
			// 	call->ra++;
			// }
			else
				swap_ab(a, A);
		}
		else if ((*a)->value == min)
		{
			swap_ab(a, A);
			rotate_ab(a, A);
			// call->ra++;
		}
		else if ((*a)->next->next->value == min)
		{
			if ((*a)->value == max)
				swap_ab(a, A);
			rev_rotate_ab(a, A);
		}
		return (1);
	}
	return (0);
}
