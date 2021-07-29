#include "../includes/push_swap.h"

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		if ((node)->next != NULL)
			tmp = (node)->next;
		else
			tmp = NULL;
		free(node);
		if (tmp != NULL)
			node = tmp;
		else
			break ;
	}
}

void	free_stack(t_node *a, t_node *b)
{
	free_node(a);
	free_node(b);
}
