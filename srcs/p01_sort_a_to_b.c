#include "../includes/push_swap.h"

void	sort_a_to_b(int size, t_node **a, t_node **b)
{
	t_call call;

	if (exceptions_under_3_a(size, a))
	{
		return ;
	}
	call_init(&call);
	get_pivots_in_a(a, size, &call);
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
		else
		{
			push_ab(b, a, B);
			call.pb++;
			if ((*b)->value >= call.pivot)
			{
				rotate_ab(b, B);
				call.rb++;
			}
		}
	}
	// printf("pivot: %d\n", call.pivot);
	// printf("big pivot: %d\n", call.big_p);
	// printf("small pivot: %d\n", call.small_p);
	// printf("ra: %d\n", call.ra);
	// printf("rb: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
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
	sort_a_to_b(call.ra, a, b);
	sort_b_to_a(call.rb, a, b);
	sort_b_to_a(call.pb - call.rb, a, b);
}

int		exceptions_under_3_a(int size, t_node **a)
{
	if (check_sorted(a))
		return(1);
	else if (size == 1)
		return (1);
	else if (size == 2)
	{
		sort_two(a, A);
		return (1);
	}
	else if (size == 3)
	{
		sort_three(size, a);
		return (1);
	}
	return (0);
}
