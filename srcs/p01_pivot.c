#include "../includes/push_swap.h"

void	set_pivots(t_node **node, int size, t_call *call)
{
	get_big_pivot(node, size, call);
	get_small_pivot(node, size, call);
}

// void	set_pivots_a(t_node **node, int size, t_call *call)
// {
// 	get_big_pivot(node, size, call);
// 	get__pivot(node, size, call);
// }

// void	set_pivots_b(t_node **node, int size, t_call *call)
// {
// 	get_small_pivot(node, size, call);
// 	get_pivot(node, size, call);
// }

void	get_pivot(t_node **node, int size, t_call *call)
{
	int i;
	int *tab;

	i = 0;
	tab = node_in_tab_sort(node, size);
	while (i < size)
	{
		if (i == (int)(size / 2))
		{
			call->pivot = tab[i];
			break ;
		}
		i++;
	}
	free(tab);
}

void	get_big_pivot(t_node **node, int size, t_call *call)
{
	int i;
	int *tab;

	i = 0;
	tab = node_in_tab_sort(node, size);
	while (i < size)
	{
		if (i == (int)(size / 2))
		{
			call->big_p = tab[i];
			break ;
		}
		i++;
	}
	free(tab);
}

void	get_small_pivot(t_node **node, int size, t_call *call)
{
	int i;
	int *tab;

	i = 0;
	tab = node_in_tab_sort(node, size);
	while (i < size)
	{
		if (i == (int)((size / 3)))
		{
			call->small_p = tab[i];
			break ;
		}
		i++;
	}
	free(tab);
}

int	*node_in_tab_sort(t_node **a, int size)
{
	t_node	*tmp;
	int		*tab;
	int		i;

	tmp = *a;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size && tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (sort_tab(tab, size));
}

int	*sort_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	k;

	k = 0;
	size = size - 1;
	while (k++ < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
	return (tab);
}
