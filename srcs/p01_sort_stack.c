#include "../includes/push_swap.h"

int		check_order(t_node **node)
{
	t_node *tmp;

	tmp = *node;
	if (*node == NULL)
		exit(0);
	while (tmp->next != NULL && tmp->value < tmp->next->value)
		tmp=tmp->next;
	if (tmp->next == NULL)
		return (1);
	return (0);
}

// void	sort(t_node **a, t_node *b)
// {
// 	int		count;

// 	count = 0;
// 	sort_a_to_b(a, b, )
// }

void	sort_a_to_b(t_node **a, t_node **b, t_info *info)
{
	int		count;
	int 	pivot;
	t_node	*tmp;
	int 	i;

	i = 0;
	count = 0;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	pivot = tmp->value;
	printf("pivot: %d\n", pivot);
	while (i < info->listsize)
	{
		if ((*a)->value > pivot)
		{
			rotate_ab(a);
			ft_putstr("ra\n");
			info->ra++;
		}
		else
		{
			push_ab(b, a);
			ft_putstr("pb\n");
			info->pb++;
		}
		i++;
	}
	i = 0;
	while (i < info->ra)
	{
		rev_rotate_ab(a);
		ft_putstr("rra\n");
		i++;
	}
	// sort_a_to_b(a, b, info);
}

// void	sort_b_to_a(t_node **a, t_node **b, t_info *info)
// {
// 	int		pivot;
// 	t_node	*tmp;
// 	int		i;
// 	int		size;

// 	i = 0;
// 	tmp = *b;
// 	size = 1;
// 	while (tmp->next != NULL)
// 	{
// 		tmp = tmp->next;
// 		size++;
// 	}
// 	pivot = tmp->value;
// 	printf("pivot: %d\n", pivot);
// 	while (i < size)
// 	{
// 		if ((*b)->value > pivot)
// 		{
// 			rotate_ab(b);
// 			ft_putstr("rb\n");
// 			info->rb++;
// 		}
// 		else
// 		{
// 			push_ab(a, b);
// 			ft_putstr("pa\n");
// 			info->pa++;
// 		}
// 	}
// 	i = 0;
// 	while (i < info->ra)
// 	{
// 		rev_rotate_ab(a);
// 		ft_putstr("rra\n");
// 		i++;
// 	}
// }

// void	set_in_order_two(t_node **a)
// {
// 	swap_ab(a);
// 	ft_putstr("sa\n");
// }

// void	set_in_order_three(t_node **a, t_info *info)
// {
// 	int i;
// 	t_node	*tmp;

// 	i = 0;
// 	while (i < info->listsize)
// 	{
// 		tmp = *a;
// 		while (tmp->next != NULL)
// 		{
// 			if (tmp->value > tmp->next->value && i == 0)
// 			{
// 				swap_ab(a);
// 				ft_putstr("sa\n");
// 			}
// 			if (tmp->value > tmp->next->value && i == 1)
// 			{
// 				swap_ab(a);
// 				ft_putstr("sa\n");
// 				rotate_ab(a);
// 				ft_putstr("ra\n");
// 			}
// 			tmp = tmp->next;
// 		}
// 		i++;
// 	}
	 
// }