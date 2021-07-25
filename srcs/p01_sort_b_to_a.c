#include "../includes/push_swap.h"

void	sort_b_to_a(int size, t_node **a, t_node **b)
{
	t_call call;

    printf("==============in b to a================\n");
    printf("size: %d\n", size);
    call_init(&call);
	if (exceptions_under_3_b(size, a, b, &call))
	{
		return ;
	}
    set_pivots(b, size, &call);
	printf("big pivot: %d\n", call.big_p);
	printf("small pivot: %d\n", call.small_p);
    while (size--)
    {
        if ((*b)->value < call.small_p)
        {
            rotate_ab(b, B);
            call.rb++;
        }
        else
        {
            push_ab(a, b, A);
            call.pa++;
            if ((*a)->value < call.big_p)
            {
                rotate_ab(a, A);
                call.ra++;
            }
        }
    }
    printf("raa: %d\n", call.ra);
	printf("rb: %d\n", call.rb);
	printf("pa: %d\n", call.pa);
	printf("pb: %d\n", call.pb);
    printf("pa-ra: %d\n", call.pa - call.ra);

    // sort_a_to_b((call.pa - call.ra), a, b);
    // printf("ra: %d\n", call.ra);
	// printf("rb: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
    // int rrr = 0;
    // int ra = 0;
    // int rb = 0;
    // if (call.ra >= call.rb)
	// {
	// 	rrr = call.rb;
	// 	ra = call.ra - rrr;
	// 	while (rrr--)
	// 		rotate_rrr(a, b, AB);
	// 	while (ra--)
	// 		rev_rotate_ab(a, A);
	// }
	// else
	// {
	// 	rrr = call.ra;
	// 	rb = call.rb - rrr;
	// 	while (rrr--)
	// 		rotate_rrr(a, b, AB);
	// 	while (rb--)
	// 		rev_rotate_ab(b, B);
	// }
    // sort_a_to_b(call.ra, a, b);
    // sort_b_to_a(call.rb, a, b);
}

int     exceptions_under_3_b(int size, t_node **a, t_node **b, t_call *call)
{
    int max;
    int min;

    (void)call;
    max = get_max(size, b);
    min = get_min(size, b);
    if (check_sorted_descending(b))
    {
        while (size--)
            push_ab(a, b, A);
        return (1);
    }
    else if (size == 1)
    {
        push_ab(a, b, A);
        return (1);
    }
    else if (size == 2)
    {
        sort_two(b, B);
		while (size--)
			push_ab(a, b, A);
        return (1);
    }
    else if (size == 3)
    {
        if ((*b)->next->next->value == max)
        {
            if((*b)->next->value == min)
                rev_rotate_ab(b, B);
            else
            {
                swap_ab(b, B);
                rev_rotate_ab(b, B);
            }
        }
        else if ((*b)->value == max)
        {
            swap_ab(b, B);
            rotate_ab(b, B);
            // call->rb++;
        }
        else if ((*b)->next->value == max)
        {
            if ((*b)->next->next->value == min)
                swap_ab(b, B);
            else
            // {
                rotate_ab(b, B);
                // call->rb++;
            // }
        }
        while (size--)
        // {
            push_ab(a, b, A);
        //     call->pa++;
        // }
        return (1);
    }
    return (0);
}