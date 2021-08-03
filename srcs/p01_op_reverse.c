/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_op_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:42 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:21:45 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** rra, rrb (reverse rotate a, reverse rotate b)
** shift down all elements of stack a by 1.
** The last element becomes the first one.
*/
void	rev_rotate_ab(t_node **node, int stack)
{
	t_node	*tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *node;
	tmp->prev = NULL;
	*node = tmp;
	(*node)->next->prev = tmp;
	if (stack == A)
		ft_putstr("rra\n");
	else if (stack == B)
		ft_putstr("rrb\n");
}

/*
** rrr
** rra and rrb at the same time.
*/
void	rotate_rrr(t_node **a, t_node **b, int stack)
{
	rev_rotate_ab(a, stack);
	rev_rotate_ab(b, stack);
	if (stack == AB)
		ft_putstr("rrr\n");
}
