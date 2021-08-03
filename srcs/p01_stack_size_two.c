/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_stack_size_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:25:38 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:25:39 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_node **a, t_node **b, int stack)
{
	if (stack == A)
	{
		if ((*a)->value > (*a)->next->value)
			swap_ab(a, A);
	}
	else if (stack == B)
	{
		if ((*b)->value < (*b)->next->value)
			swap_ab(b, B);
		push_ab(a, b, A);
		push_ab(a, b, A);
	}
}
