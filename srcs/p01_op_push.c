/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_op_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:27 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:21:29 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** pa, pb (push a, push b)
** take the first element at the top of b and put it at the top of a. \
** Do nothing if b is empty.
*/
void	push_ab(t_node **dest, t_node **src, int stack)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = tmp;
	*dest = tmp;
	if (stack == A)
		ft_putstr("pa\n");
	else if (stack == B)
		ft_putstr("pb\n");
}
