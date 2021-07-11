/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ver1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/07/02 16:18:48 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_info	info;
	int		i;
	int		j;
	int		len;

	ft_init(&info);
	j = 0;
	if (ac < 2)
		ft_exit_msg("ERROR: Argument not enough");
	else
	{
		//make one argument in one string
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
		** DONT FORGET:	info.arg
						info.check need to be freed
		*/
		//count how many arguemnt exist
		i = 0;
		info.count = count_arg(info.string);
		//printf("count: %d\n", info.count);

		//split argument
		info.arg = ft_split(info.string, ' ');
		if (!info.arg)
			ft_exit_msg("ERROR: Arguement split failed");

		//info.check calloc
		info.check = ft_calloc(info.count + 1, sizeof(char **));
		if (!info.check)
			ft_exit_msg("ERROR: Array malloc failed");
		while (i < info.count)
		{
			len = ft_strlen(info.arg[i]);
			info.check[i] = ft_calloc(len + 1, sizeof(char *));
			if (!info.check[i])
				ft_exit_msg("ERROR: Array malloc failed");
			i++;
		}

		//check valid arguments and doubled arguments
		i = 0;
		while (info.arg[i])
		{
			if (!info.arg[i] || !ft_only_digit(info.arg[i]))
				ft_exit_msg("ERROR: Argument invalide");
			if (check_double(info.check, info.arg[i]) != 0)
			{
				ft_strcpy(info.check[j], info.arg[i]);
				printf("info check : %s\n", info.check[j]);
				j++;
			}
			else
			{
				printf("info check : %s\n", info.check[j]);
				printf("info arg : %s\n", info.arg[i]);
			 	ft_exit_msg("ERROR: The same arguement detected (Arguement cannot be doubled)");
			}
			printf("arg %d : %s\n", i, info.arg[i]);
			i++;
		}
		ft_free_tab2(info.check);
	}
	// printf("%s\n", info.string);
	free(info.string);
	return (EXIT_SUCCESS);
}

// int		check_double(char **s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		if (ft_strcmp(s1[i], s2) == 0) //if two string is the same, it returns 0
// 			return (0);
// 		i++;
// 	}
// 	return (i);
// }

// int	count_arg(char *str)
// {
// 	int i;
// 	int count;

// 	i = 0;
// 	count = 0;
// 	while(str[i])
// 	{
// 		if (str[i] == ' ')
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }