#include "../includes/push_swap.h"

int     *node_in_tab(t_node **a, int size)
{
	t_node	*tmp;
	int		*tab;
	int		i;

	tmp = *a;
	tab = malloc(sizeof(int) * size);
	i = 0;
	while (i < size && tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (tab);	
}