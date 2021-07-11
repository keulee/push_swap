#include "../includes/push_swap.h"

int		check_sorted(t_node **node)
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

void	sort_a_to_b(int size, t_node **a, t_node **b)
{
	t_call	call;
	int		s_tmp;
	int		i;

	i = 0;
	s_tmp = size;
	call_init(&call);
	get_max_pivot(a, &call);
	get_min_pivot(a, &call);
	printf("pivot: %ld\n", call.p_max);
	printf("pivot: %ld\n", call.p_min);
	if (s_tmp < 3)
	 return ;
	while (s_tmp)
	{
		if ((*a)->value >= call.p_max)
		{
			rotate_ab(a);
			ft_putstr("ra\n");
			call.ra++;
		}
		else
		{
			push_ab(b, a);
			ft_putstr("pb\n");
			call.pb++;
			if ((*b)->value >= call.p_min)
			{
				rotate_ab(b);
				ft_putstr("rb\n");
				call.rb++;
			}
		}
		s_tmp--;
	}
	printf("ra: %d\n", call.ra);
	printf("pb: %d\n", call.pb);
	i = 0;
	while (i < call.ra)
	{
		rev_rotate_ab(a);
		ft_putstr("rra\n");
		i++;
	}
	i = 0;
	while (i < call.rb)
	{
		rev_rotate_ab(b);
		ft_putstr("rrb\n");
		i++;
	}
	sort_a_to_b(call.ra, a, b);
	sort_b_to_a(call.rb, a, b);
	sort_b_to_a(call.pb - call.rb, a, b);
}

void	sort_b_to_a(int size, t_node **a, t_node **b)
{
	t_call	call;
	int		s_tmp;
	int 	i;

	i = 0;
	s_tmp = size;
	call_init(&call);
	get_max_pivot(b, &call);
	get_min_pivot(b, &call);
	printf("pivot: %ld\n", call.p_max);
	printf("pivot: %ld\n", call.p_min);
	if (s_tmp < 3)
	 return ;
	while (s_tmp)
	{
		if ((*b)->value < call.p_min)
		{
			rotate_ab(b);
			ft_putstr("rb\n");
			call.rb++;
		}
		else
		{
			push_ab(a, b);
			ft_putstr("pa\n");
			call.pa++;
			// printf("b top : %d\n", (*b)->value);
			// print_node_a(*a);
			// print_node_b(*b);
			if (*b && (*b)->value < call.p_max)
			{
				rotate_ab(a);
				ft_putstr("ra\n");
				call.ra++;
			}
		}
		s_tmp--;
	}
	printf("ra: %d\n", call.ra);
	printf("pb: %d\n", call.pb);
	sort_a_to_b(call.pb - call.ra, a, b);
	i = 0;
	while (i < call.ra)
	{
		rev_rotate_ab(a);
		ft_putstr("rra\n");
		i++;
	}
	i = 0;
	while (i < call.rb)
	{
		rev_rotate_ab(b);
		ft_putstr("rrb\n");
		i++;
	}
	sort_a_to_b(call.ra, a, b);
	// sort_b_to_a(call.rb, a, b);
}