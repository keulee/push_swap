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

void	sort_a_to_b(t_node **a, t_node **b, t_info *info)
{
	int 	pivot;
	t_node	*tmp;
	int i;

	i = 0;
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
		// print_node_a(*a);
		// print_node_b(*b);
		i++;
	}
	i = 0;
		printf("ra: %d\n", info->ra);

	while (i < info->ra)
	{
		// printf("ra: %d\n", info->ra);
		// exit(0);
		rev_rotate_ab(a);
		ft_putstr("rra\n");
		// print_node_a(*a);

		i++;
	}
	// print_node_a(*a);

}

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