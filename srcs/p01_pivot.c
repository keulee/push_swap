#include "../includes/push_swap.h"

void		get_max_pivot(t_node **node, t_call *call)
{
	t_node *tmp;
	long	nbr;

	// if (!*node) //protege ?
		// return ;
	tmp = *node;
	nbr = tmp->value;
	while (tmp != NULL)
	{
		if (nbr < tmp->value)
			nbr = tmp->value;
		tmp = tmp->next;
	}
	call->p_max = nbr;
}

void		get_min_pivot(t_node **node, t_call *call)
{
	t_node *tmp;
	long	nbr;

	// if (!*node) //protege ?
		// return  ;
	tmp = *node;
	nbr = tmp->value;
	while (tmp != NULL)
	{
		if (nbr > tmp->value)
			nbr = tmp->value;
		tmp = tmp->next;
	}
	call->p_min = nbr;
}