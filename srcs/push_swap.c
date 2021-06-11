/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/06/11 18:54:16 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	int		i;
	int		j;

	(void)ac;
	ft_init(&info);
	// if (ac < 2)
		// ft_exit_msg("ERROR: Argument not enough"); //need to fix?????
	// else
	// {
	i = 1;
	while (av[i])
	{
		info.tmp = ft_split(av[i], ' ');
		j = 0;
		while(info.tmp[j])
		{
			printf("tmp[%d]: %s\n", j, info.tmp[j]);
			j++;
		}
		ft_free_tab2(info.tmp);
		i++;
	}
	return (EXIT_SUCCESS);
}
