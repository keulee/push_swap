/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/06/21 22:03:21 by keulee           ###   ########.fr       */
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
			insert_value(&info.stack_a, info.arg);
			find_double(info.stack_a, info.arg);
			info.listsize++;
			j++;
		}
		ft_free_tab2(info.tmp);
		i++;
	}
	print_node(info.stack_a);
	print_node(info.stack_b);
	swap_ss(&info.stack_a, &info.stack_b);
	printf("-------------------\n");
	print_node(info.stack_a);
	print_node(info.stack_b);
	return (EXIT_SUCCESS);
}