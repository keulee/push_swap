#include "../includes/push_swap.h"

void	sort_b_to_a(int size, t_node **a, t_node **b)
{
	t_call call;

    // printf("==============in b to a================\n");
    // printf("size in b: %d\n", size);
    call_init(&call);
    set_pivots(b, size, &call);
	if (exceptions_under_3_b(size, a, b))
	{
		return ;
	}
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
    sort_a_to_b((call.pa - call.ra), a, b);
    int rrr = 0;
    int ra = 0;
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
    sort_b_to_a(call.rb, a, b);
}

int     exceptions_under_3_b(int size, t_node **a, t_node **b)
{
    int max;
    int min;

    max = get_max(size, b);
    min = get_min(size, b);
    // if (size == 1)
    // {
    //     push_ab(a, b, A);
    //     return (1);
    // }
    if (size == 2)
    {
        sort_two(b, B);
		push_ab(a, b, A);
		push_ab(a, b, A);
        return (1);
    }
    // if (size == 3 && get_listsize(b) == 3)
    // {
    //     if ((*b)->next->next->value == max)
    //     {
    //         if((*b)->next->value == min)
    //             rev_rotate_ab(b, B);
    //         else if ((*b)->value == min)
    //         {
    //             swap_ab(b, B);
    //             rev_rotate_ab(b, B);
    //         }
    //     }
    //     else if ((*b)->value == max)
    //     {
    //         swap_ab(b, B);
    //         rotate_ab(b, B);
    //     }
    //     else if ((*b)->next->value == max)
    //     {
    //         if ((*b)->next->next->value == min)
    //             swap_ab(b, B);
    //         else if ((*b)->value == min)
    //             rotate_ab(b, B);
    //     }
    //     push_ab(a, b, A);
    //     push_ab(a, b, A);
    //     push_ab(a, b, A);
    //     return (1);
    // }
    if (size == 3)
    {
        push_ab(a, b, A);
        push_ab(a, b, A);
        push_ab(a, b, A);
        sort_a_to_b(3, a, b);
        return (1);
    }
    if (check_sorted_descending(b, size))
    {
        while (size)
        {
            push_ab(a, b, A);
            size--;
        }
        return (1);
    }
    return (0);
}