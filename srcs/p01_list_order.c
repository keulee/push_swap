#include "../includes/push_swap.h"

int		check_order(t_node **node)
{
	t_node *tmp;

	tmp = *node;
	if (*node == NULL)
		exit(0);
	while (tmp->next != NULL && tmp->value < tmp->next->value)
	{
		// printf("tmp->value: %d\n", tmp->value);
		// printf("tmp->next->value: %d\n", tmp->next->value);
		// if (tmp->value < tmp->next->value)
		tmp=tmp->next;
			// ft_exit_msg("tri");
			// return (0);
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}