/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/06/26 23:01:56 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	int		i;
	int		j;

	ft_init(&info);
	i = 1;
	if (ac == 1)
		exit(0);
	while (av[i])
	{
		info.tmp = ft_split(av[i], ' ');
		j = 0;
		while(info.tmp[j])
		{
			value_check(info.tmp[j], &info);
			// printf("int value : %ld\n", info.arg);
			insert_node(&info.stack_a, info.arg);
			find_double(info.stack_a, info.arg);
			info.listsize++;
			j++;
		}
		ft_free_tab2(info.tmp);
		i++;
	}
	// insert_node(&info.stack_b, 122);
	// insert_node(&info.stack_b, 0);
	// insert_node(&info.stack_b, -42);
	print_node_a(info.stack_a);
	print_node_b(info.stack_b);
	// swap_ab(&info.stack_a);
	// swap_ss(&info.stack_a, &info.stack_b);
	// push_ab(&info.stack_b, &info.stack_a);
	// push_ab(&info.stack_a, &info.stack_b);
	// push_ab(&info.stack_b, &info.stack_a);
	// rotate_ab(&info.stack_a);
	// rotate_ab(&info.stack_b);
	// rotate_rr(&info.stack_a, &info.stack_b);
	// rev_rotate_ab(&info.stack_a);
	// rev_rotate_ab(&info.stack_b);
	rotate_rrr(&info.stack_a, &info.stack_b);
	printf("---------after---------\n");
	print_node_a(info.stack_a);
	print_node_b(info.stack_b);
	return (EXIT_SUCCESS);
}