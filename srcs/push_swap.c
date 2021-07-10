/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/07/10 21:58:56 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);
	printf("---------before---------\n");
	print_node_a(info.stack_a);//, &info);
	print_node_b(info.stack_b);
	if (check_order(&info.stack_a))
	{
		free_stack(info.stack_a, info.stack_b);
		return (EXIT_SUCCESS);
	}
	else
	{
		sort_a_to_b(&info.stack_a, &info.stack_b, &info);
	}
	printf("---------after---------\n");
	print_node_a(info.stack_a);//, &info);
	print_node_b(info.stack_b);
	// free_stack(info.stack_a, info.stack_b);
	return (EXIT_SUCCESS);
}