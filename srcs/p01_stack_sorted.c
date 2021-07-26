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

int		check_sorted_descending(t_node **node, int size)
{
	t_node *tmp;
	int i;

	tmp = *node;
	i = 0;
	if (*node == NULL)
		exit(0);
	while (i < size && tmp->next != NULL && tmp->value > tmp->next->value)
		tmp=tmp->next;
	if (tmp->next == NULL)
		return (1);
	return (0);
}

int		check_sorted_with_size(t_node **node, int size)
{
	t_node *tmp;
	int i;

	tmp = *node;
	i = 0;
	if (*node == NULL)
		exit(0);
	while (i++ < size - 1)
	{
		if (tmp->value < tmp->next->value)
			tmp=tmp->next;
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}