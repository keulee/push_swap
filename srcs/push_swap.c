/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:51:16 by keulee            #+#    #+#             */
/*   Updated: 2021/06/13 23:58:25 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_node(t_node **node, int value)
{
	t_node *new;
	t_node *tmp;

	new = (t_node *)malloc(sizeof(t_node));
	tmp = *node;

	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	
	printf("value in node : %d\n", value);

	//if there's no node.
	if (tmp == NULL)
	{
		*node = new;
		return ;
	}

	//find the last node in the linked list
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	value_check(char *str, int neg)
{
	int i;

	i = 0;
	if (neg == 1)
		i++;
	if (!ft_only_digit(&str[i]))
		ft_exit_msg("ERROR: Argument not int");
}

int	main(int ac, char **av)
{
	t_info	info;
	int		i;
	int		j;
	int		k = 0;
	long	arg;
	int		neg;

	(void)ac;
	ft_init(&info);
	i = 1;
	while (av[i])
	{
		info.tmp = ft_split(av[i], ' ');
		j = 0;
		while(info.tmp[j])
		{
			neg = 0;
			// printf("tmp[%d]: %s\n", j, info.tmp[j]);
			if (ft_strncmp(info.tmp[j], "-", 1) == 0)
				neg = 1;
			// printf("%d\n", neg);
			// if (!ft_only_digit(info.tmp[j]))
			// 	ft_exit_msg("ERROR: Argument not int");
			value_check(info.tmp[j], neg);
			arg = 0;
			k = 0;
			if (neg == 1)
				k++;
			while (ft_digit(info.tmp[j][k]))
			{
				arg = arg * 10 + (info.tmp[j][k] - 48);
				k++;
			}
			if (arg > 2147483647)
				ft_exit_msg("ERROR: arg overflow int");
			printf("int value : %ld\n", arg);
			//insert_node(&info.head, arg);	
			j++;
		}
		ft_free_tab2(info.tmp);
		i++;
	}
	return (EXIT_SUCCESS);
}