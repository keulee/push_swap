/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_exception_a_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:20:30 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:20:34 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exception_size_under_3a(t_node **a, t_node **b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		sort_two(a, b, A);
		return ;
	}
	else if (size == 3 && get_listsize(a) == 3)
	{
		if (check_sorted_with_size(a, 3))
			return ;
		else
			sort_three(3, a);
		return ;
	}
	else if (size == 3)
	{
		exception_size_3a(a, b, size);
		return ;
	}
}

void	exception_size_3a(t_node **a, t_node **b, int size)
{
	int	max;
	int	min;

	max = get_max(size, a);
	min = get_min(size, a);
	if (check_sorted_with_size(a, 3))
		return ;
	if ((*a)->next->next->value == max)
	{
		swap_ab(a, A);
		return ;
	}
	size_3_max_first(a, b, max, min);
	return ;
}

void	size_3_max_first(t_node **a, t_node **b, int max, int min)
{
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
	return ;
}

void	exception_size_5a(t_node **a, t_node **b, int size)
{
	if (check_sorted_with_size(a, 5))
		return ;
	sort_size_5a(a, b, size);
	exception_size_3a(a, b, 3);
	sort_two(a, b, B);
	return ;
}

void	sort_size_5a(t_node **a, t_node **b, int size)
{
	int	mid;
	int	pb;
	int	ra;

	mid = get_mid_value_in_five(a, size);
	pb = 0;
	ra = 0;
	while (size--)
	{
		if ((*a)->value < mid)
		{
			push_ab(b, a, B);
			pb++;
		}
		else if ((*a)->value >= mid)
		{
			rotate_ab(a, A);
			ra++;
		}
		if (pb == 2)
			break ;
	}
	while (ra--)
		rev_rotate_ab(a, A);
}
