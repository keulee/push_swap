#include "../includes/push_swap.h"

int	check_sorted(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	if (!*node)
		exit(0);
	else if (*node)
	{
		while (tmp->next != NULL && tmp->value < tmp->next->value)
			tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}

int	check_sorted_with_size(t_node **node, int size)
{
	t_node	*tmp;
	int		i;

	tmp = *node;
	i = 0;
	if (*node)
	{
		while (i < size - 1 && tmp->next != NULL)
		{
			if (tmp->value > tmp->next->value)
				return (0);
			tmp = tmp->next;
			i++;
		}
	}
	if (i != size - 1)
		return (0);
	return (1);
}

int	check_sorted_descending(t_node **node, int size)
{
	t_node	*tmp;
	int		i;

	tmp = *node;
	i = 0;
	if (*node)
	{
		while (i < size - 1 && tmp->next != NULL)
		{
			if (tmp->value < tmp->next->value)
				return (0);
			tmp = tmp->next;
			i++;
		}
	}
	if (i != size - 1)
		return (0);
	return (1);
}
