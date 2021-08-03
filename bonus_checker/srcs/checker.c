/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:31:27 by keulee            #+#    #+#             */
/*   Updated: 2021/08/03 16:31:28 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_info	info;
	char	*buf;

	ft_init(&info);
	if (ac == 1)
		exit(0);
	create_stack(&info, av);
	if (info.stack_a == NULL && info.stack_b == NULL)
		exit(0);
	while ((get_next_line(0, &buf)) > 0)
	{
		checker_process(buf, &info.stack_a, &info.stack_b);
		free(buf);
	}
	free(buf);
	if (check_sorted(&info.stack_a) && info.stack_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(info.stack_a, info.stack_b);
	return (EXIT_SUCCESS);
}
