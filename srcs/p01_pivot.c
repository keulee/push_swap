#include "../includes/push_swap.h"

void		get_max_pivot(int size, t_node **node, t_call *call)
{
	t_node *tmp;
	long	nbr;

	tmp = *node;
	nbr = tmp->value;
	// while (tmp != NULL)
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
	call->p_max = nbr;
}

void		get_min_pivot(int size, t_node **node, t_call *call)
{
	t_node *tmp;
	long	nbr;


	tmp = *node;
	nbr = tmp->value;
	// while (tmp != NULL)
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
	call->p_min = nbr;
}