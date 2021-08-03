/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p01_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:20:56 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:20:58 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		if ((node)->next != NULL)
			tmp = (node)->next;
		else
			tmp = NULL;
		free(node);
		if (tmp != NULL)
			node = tmp;
		else
			break ;
	}
}

void	free_stack(t_node *a, t_node *b)
{
	free_node(a);
	free_node(b);
}
