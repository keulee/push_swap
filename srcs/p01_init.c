/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:16 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:21:17 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_info *info)
{
	info->i = 1;
	info->j = 0;
	info->tmp = NULL;
	info->stack_a = NULL;
	info->stack_b = NULL;
	info->arg = 0;
	info->listsize = 0;
}

void	call_init(t_call *call)
{
	call->pa = 0;
	call->pb = 0;
	call->ra = 0;
	call->rb = 0;
	call->big_p = 0;
	call->small_p = 0;
}
