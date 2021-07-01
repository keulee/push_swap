#include "../includes/push_swap.h"

void	check_order(t_node **node)
{
	t_node *tmp;

	tmp = *node;
	if (*node == NULL)
		exit(0);
	while (tmp->next != NULL)
	{
		// printf("tmp->value: %d\n", tmp->value);
		// printf("tmp->next->value: %d\n", tmp->next->value);
		if (tmp->value < tmp->next->value)
			tmp=tmp->next;
		else
			ft_exit_msg("tri");
	}
	exit(0);
}