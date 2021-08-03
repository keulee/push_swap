/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_sort_a_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:24:43 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:24:46 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a_to_b(int size, t_node **a, t_node **b, int *flag)
{
	t_call	call;

	if (exceptions_a_to_b(size, a, b))
		return ;
	call_init(&call);
	set_pivots(a, size, &call);
	while (size--)
		rotate_push_b(a, b, &call);
	if (call.ra >= call.rb)
		rev_rotate_ra_flag(a, b, &call, flag);
	else
		rev_rotate_rb_flag(a, b, &call, flag);
	sort_a_to_b(call.ra, a, b, flag);
	sort_b_to_a(call.rb, a, b, flag);
	sort_b_to_a(call.pb - call.rb, a, b, flag);
}

void	rotate_push_b(t_node **a, t_node **b, t_call *call)
{
	if ((*a)->value >= call->big_p)
	{
		call->ra++;
		rotate_ab(a, A);
	}
	else if ((*a)->value < call->big_p)
	{
		call->pb++;
		push_ab(b, a, B);
		if ((*b)->value >= call->small_p)
		{
			call->rb++;
			rotate_ab(b, B);
		}
	}
}

void	rev_rotate_ra_flag(t_node **a, t_node **b, t_call *call, int *flag)
{
	int	rrr;
	int	rra;

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

void	rev_rotate_rb_flag(t_node **a, t_node **b, t_call *call, int *flag)
{
	int	rrr;
	int	rrb;

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

int	exceptions_a_to_b(int size, t_node **a, t_node **b)
{
	if (size <= 3)
	{
		exception_size_under_3a(a, b, size);
		return (1);
	}
	else if (size == 5)
	{
		exception_size_5a(a, b, 5);
		return (1);
	}
	return (0);
}
