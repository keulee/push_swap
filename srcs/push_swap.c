/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/06/08 23:45:13 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	int		i;
	int		j;

	ft_init(&info);
	j = 0;
	if (ac < 2)
		ft_exit_msg("ERROR: Argument not enough");
	else
	{
		info.string = ft_strjoin(av[1], " ");
		i = 2;
		while (i < ac)
		{
			info.av_with_space = ft_strjoin(av[i], " ");
			info.string = ft_make_string(info.string, info.av_with_space);
			free(info.av_with_space);
			info.av_with_space = NULL;
			i++;
		}
		/*
		** DONT FORGET : info.arg need to be freed
		*/
		info.count = count_arg(info.string);
		printf("count: %d\n", info.count);
		info.arg = ft_split(info.string, ' ');
		if (!info.arg)
			ft_exit_msg("ERROR: Arguement split failed");
		i = 0;
		while (info.arg[i])
		{
			if (!info.arg[i] || !ft_only_digit(info.arg[i]))
				ft_exit_msg("ERROR: Not valid argument");
			// if (!check_double(info.check, info.arg[i]))
			// 	info.check[j] = ft_strcpy(info.check[j], info.arg[i]);
			// else
			// 	ft_exit_msg("ERROR: The same arguement detected. (Arguement cannot be doubled)");
			printf("arg %d : %s\n", i, info.arg[i]);
			i++;
		}
	}
	// printf("%s\n", info.string);
	free(info.string);
	return (EXIT_SUCCESS);
}
