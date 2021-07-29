#include "../includes/push_swap.h"

int	get_max(int size, t_node **node)
{
	t_node	*tmp;
	int		nbr;

	tmp = *node;
	nbr = tmp->value;
	while (size)
	{
		if (nbr < tmp->value)
			nbr = tmp->value;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		size--;
	}
	return (nbr);
}

int	get_min(int size, t_node **node)
{
	t_node	*tmp;
	int		nbr;

	tmp = *node;
	nbr = tmp->value;
	while (size)
	{
		if (nbr > tmp->value)
			nbr = tmp->value;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
		size--;
	}
	return (nbr);
}
