/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_sort_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:25:04 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:25:06 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_less_five(t_info *info)
{
	if (info->listsize == 2)
		sort_two(&info->stack_a, &info->stack_b, A);
	else if (info->listsize == 3)
		sort_three(info->listsize, &info->stack_a);
	else if (info->listsize <= 5)
		sort_five(info->listsize, &info->stack_a, &info->stack_b);
}

void	sort_recursive_push_swap(t_info *info)
{
	int	flag;

	flag = 0;
	sort_a_to_b(info->listsize, &info->stack_a, &info->stack_b, &flag);
}
