/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/08/02 22:55:24 by keulee           ###   ########.fr       */
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
	if (check_sorted(&info.stack_a))
	{
		free_stack(info.stack_a, info.stack_b);
		return (EXIT_SUCCESS);
	}
	else
	{
		if (info.listsize <= 5)
			sort_less_five(&info);
		else
			sort_recursive_push_swap(&info);
	}	
	free_stack(info.stack_a, info.stack_b);
	return (EXIT_SUCCESS);
}
