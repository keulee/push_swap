/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_exception_b_to_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:20:46 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:20:47 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exception_size_under_3b(t_node **a, t_node **b, int size)
{
	if (size == 2)
	{
		sort_two(a, b, B);
		return ;
	}
	else if (size == 3)
	{
		push_ab(a, b, A);
		push_ab(a, b, A);
		push_ab(a, b, A);
		exception_size_3a(a, b, 3);
		return ;
	}
}

void	exception_size_5b(t_node **a, t_node **b, int size)
{
	int	max;
	int	min;

	if (check_sorted_descending(a, 5))
		return ;
	sort_size_5b(a, b, size);
	max = get_max(3, a);
	min = get_min(3, a);
	if (check_sorted_with_size(a, 3))
	{
		sort_two(a, b, B);
		return ;
	}
	else if ((*a)->next->next->value == max)
	{
		swap_ab(a, A);
		sort_two(a, b, B);
		return ;
	}
	size_3_max_first(a, b, max, min);
	sort_two(a, b, B);
	return ;
}

void	sort_size_5b(t_node **a, t_node **b, int size)
{
	int	mid;
	int	pa;
	int	rb;

	mid = get_mid_value_in_five(b, size);
	pa = 0;
	rb = 0;
	while (size--)
	{
		if ((*b)->value >= mid)
		{
			push_ab(a, b, A);
			pa++;
		}
		else if ((*b)->value < mid)
		{
			rotate_ab(b, B);
			rb++;
		}
		if (pa == 3)
			break ;
	}
	while (rb--)
		rev_rotate_ab(b, B);
}
