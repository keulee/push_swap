#include "../includes/push_swap.h"

void	sort_five(int size, t_node **a, t_node **b)
{
	int	mid;
	int	pb;

	pb = 0;
	mid = get_mid_value_in_five(a, size);
	while (1)
	{
		if ((*a)->value < mid)
		{
			push_ab(b, a, B);
			pb++;
		}
		else if ((*a)->value >= mid)
			rotate_ab(a, A);
		if (pb == 2)
			break ;
	}
	sort_three(3, a);
	sort_two(a, b, B);
}

int	get_mid_value_in_five(t_node **a, int size)
{
	t_node	*tmp;
	int		*tab;
	int		i;
	int		mid;

	tmp = *a;
	tab = malloc(sizeof(int) * size);
	i = 0;
	while (i < size && tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	mid = sort_tab_get_mid(tab, size);
	free(tab);
	return (mid);
}

int	sort_tab_get_mid(int *tab, int size)
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
	return (tab[2]);
}
