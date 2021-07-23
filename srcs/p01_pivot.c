#include "../includes/push_swap.h"

int		*sort_tab(int *tab, int size)
{
	int tmp;
	int i;
	int k;

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

int     *node_in_tab_sort(t_node **a, int size)
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

void     get_pivot(int *tab, int size, t_call *call)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (i == (int)(size / 2))
            call->pivot = tab[i];
        else if (i == (int)((size / 4) + 0.5))
            call->small_p = tab[i];
        else if (i == (int)(((size / 4) * 3) + 0.5))
            call->big_p = tab[i];
        if (call->pivot && call->big_p && call->small_p)
            break;
        i++;
    }
}