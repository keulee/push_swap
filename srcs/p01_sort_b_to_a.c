/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_sort_b_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:24:52 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:24:54 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_to_a(int size, t_node **a, t_node **b, int *flag)
{
	t_call	call;

	(*flag)++;
	if (exceptions_b_to_a(size, a, b))
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

int	exceptions_b_to_a(int size, t_node **a, t_node **b)
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
	return (0);
}
