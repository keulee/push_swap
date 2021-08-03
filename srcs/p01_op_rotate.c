/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_op_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:54 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:21:55 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** ra, rb (rotate a, rotate b)
** shift up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	rotate_ab(t_node **node, int stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	*node = tmp->next;
	tmp2 = *node;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	tmp->prev = tmp2;
	if (stack == A)
		ft_putstr("ra\n");
	else if (stack == B)
		ft_putstr("rb\n");
}

/*
** rr
** ra and rb at the same time.
*/
void	rotate_rr(t_node **a, t_node **b, int stack)
{
	rotate_ab(a, stack);
	rotate_ab(b, stack);
	if (stack == AB)
		ft_putstr("rr\n");
}
