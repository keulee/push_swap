/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/07/04 20:11:10 by keulee           ###   ########.fr       */
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
	print_node_a(info.stack_a);
	print_node_b(info.stack_b);
	if (!check_order(&info.stack_a))
	{
		// ft_exit_msg("tri");
		// if (info.listsize == 2)
		// set_in_order_two(&info.stack_a);
		// set_in_order_three(&info.stack_a, &info);
		sort_a_to_b(&info.stack_a, &info.stack_b, &info);
	}
	printf("---------after---------\n");
	print_node_a(info.stack_a);
	print_node_b(info.stack_b);
	// return (EXIT_SUCCESS);
	exit(0);
}