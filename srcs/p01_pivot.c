#include "../includes/push_swap.h"

int		get_max(int size, t_node **node)
{
	t_node *tmp;
	int	nbr;

	tmp = *node;
	nbr = tmp->value;
	while(size)
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

int		get_min(int size, t_node **node)
{
	t_node *tmp;
	int	nbr;
	
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

void	get_pivot(int size, t_node **node, t_call *call)
{
	long	min;
	long	max;

	min = get_min(size, node);
	max = get_max(size, node);
	call->p_big = (min + max) / 2;
	call->p_small = (min + call->p_big) / 2;
}

int		get_last_value(t_node **node)
{
	int	last;
	t_node	*tmp;

	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	last = tmp->value;
	return (last);
}

// long	get_mid_value(t_node **node)
// {
// 	long	mid;

// 	mid = (*node)->next->value;
// 	return (mid);
// }
