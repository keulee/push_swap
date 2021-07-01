/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/07/01 16:59:52 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	putnbr_stack(&info, av);
	// printf("---------before---------\n");
	// insert_node(&info.stack_b, 122);
	// print_node_a(info.stack_a);
	// print_node_b(info.stack_b);
	if(!check_order(&info.stack_a))
		ft_exit_msg("tri");
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
	// rotate_rrr(&info.stack_a, &info.stack_b);
	// printf("---------after---------\n");
	// print_node_a(info.stack_a);
	// print_node_b(info.stack_b);
	return (EXIT_SUCCESS);
}

void	putnbr_stack(t_info *info, char **av)
{
	while (av[info->i])
	{
		info->tmp = ft_split(av[info->i], ' ');
		info->j = 0;
		while(info->tmp[info->j])
		{
			value_check(info->tmp[info->j], info);
			insert_node(&info->stack_a, info->arg);
			find_double(info->stack_a, info->arg);
			info->listsize++;
			info->j++;
		}
		ft_free_tab2(info->tmp);
		info->i++;
	}
}