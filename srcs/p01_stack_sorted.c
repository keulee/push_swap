#include "../includes/push_swap.h"

int		check_sorted(t_node **node)
{
	t_node *tmp;

	tmp = *node;
	if (*node == NULL)
		exit(0);
	while (tmp->next != NULL && tmp->value < tmp->next->value)
		tmp=tmp->next;
	if (tmp->next == NULL)
		return (1);
	return (0);
}