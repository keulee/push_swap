/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/07/14 01:28:34 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	int		o_size;
	
	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);

	o_size = info.listsize;
	printf("---------before---------\n");
	print_node_a(info.stack_a);
	print_node_b(info.stack_b);
	
	if (check_sorted(&info.stack_a))
	{
		free_stack(info.stack_a, info.stack_b);
		printf("OK - ALREADY SORTED\n");
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("SORTING...\n");
		if (info.listsize <= 3)
			sort_max_three(info.listsize, &info.stack_a);
		else if (info.listsize <= 5)
			sort_max_five(info.listsize, &info.stack_a, &info.stack_b);
		// sort_a_to_b(info.listsize, &info.stack_a, &info.stack_b);
	}

	if (!check_sorted(&info.stack_a) || o_size != get_listsize(&info.stack_a))
	{
		printf("KO - SORT AGAIN\n");
		printf("listsize = %d\n", get_listsize(&info.stack_a));
	}
	else
		printf("OK - SORT SUCCESS\n");
	
	printf("---------after---------\n");
	print_node_a(info.stack_a);
	print_node_b(info.stack_b);
	
	free_stack(info.stack_a, info.stack_b);
	return (EXIT_SUCCESS);
}