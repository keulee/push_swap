/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/06/17 22:10:16 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_node(t_node *node, t_info *info)
{
	int i;

	i = 0;
	while (i < info->listsize)
	{
		printf("node [%d] : %d\n", i, node->value);
		node = node->next; 
		i++;
	}
}

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
			printf("int value : %ld\n", info.arg);
			insert_value(&info.head, info.arg);
			find_double(info.head, info.arg);
			info.listsize++;
			j++;
		}
		print_node(info.head, &info);
		ft_free_tab2(info.tmp);
		i++;
	}
	return (EXIT_SUCCESS);
}