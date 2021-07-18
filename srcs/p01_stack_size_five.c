#include "../includes/push_swap.h"

void	sort_five(int size, t_node **a, t_node **b)
{
	int		mid;
	int		pb;
	int		size_a;
	int		size_b;

	pb = 0;
	mid = get_mid_value_in_five(a, size);
	while (size--)
	{
		if ((*a)->value < mid)
		{
			push_ab(b, a, B);
			pb++;
		}
		else
			rotate_ab(a, A);
	}
	size_a = get_listsize(a);
	size_b = get_listsize(b); 
	if (size_a == 2 && !check_sorted(a))
		sort_two(a, A);
	else if (size_a == 3 && !check_sorted(a))
		sort_three(3, a);
	if (size_b == 2)
	{
		sort_two(b, B);
		while (size_b--)
			push_ab(a, b, A);
	}
	else
		push_ab(a, b, A);
}

int		get_mid_value_in_five(t_node **a, int size)
{
	t_node	*tmp;
	int		tab[size];
	int		i;

	tmp = *a;
	i = 0;
	while (i < size && tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (ft_sort_int_tab(tab, size));	
}

int		ft_sort_int_tab(int *tab, int size)
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
				i++;
			}
			else
				i++;
		}
	}
	return (tab[2]);
}