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

int	main(int ac, char **av)
{
	t_info	info;
	int		i;
	int		j;
	int		k = 0;
	int		arg;

	(void)ac;
	ft_init(&info);
	i = 1;
	while (av[i])
	{
		info.tmp = ft_split(av[i], ' ');
		j = 0;
		while(info.tmp[j])
		{
			// printf("tmp[%d]: %s\n", j, info.tmp[j]);
			if (!ft_only_digit(info.tmp[j]))
				ft_exit_msg("ERROR: Argument not int");
			arg = 0;
			k = 0;
			while (ft_digit(info.tmp[j][k]))
			{
				arg = arg * 10 + (info.tmp[j][k] - 48);
				k++;
			}
			printf("int value : %d\n", arg);
			insert_node(&info.head, arg);	
			j++;
		}
		ft_free_tab2(info.tmp);
		i++;
	}
	return (EXIT_SUCCESS);
}
