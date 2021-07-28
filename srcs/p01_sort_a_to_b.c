#include "../includes/push_swap.h"

void	sort_a_to_b(int size, t_node **a, t_node **b)
{
	t_call call;


    // printf("==============in a to b================\n");
    // printf("size in a: %d\n", size);
	call_init(&call);
	set_pivots(a, size, &call);
	if (exceptions_under_3_a(size, a, b))
	{
		return ;
	}
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
	int rrr = 0;
	int	ra = 0;
	int rb = 0;
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
	// printf("pb - rb: %d\n", call.pb - call.rb);
	sort_b_to_a(call.pb - call.rb, a, b);
}

int		exceptions_under_3_a(int size, t_node **a, t_node **b)
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
	return (0);
}
