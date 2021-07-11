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
	if (size <= 3)
		return ;
	call_init(&call);
	get_max_pivot(size, a, &call);
	get_min_pivot(size, a, &call);
	printf("pivot: %ld\n", call.p_max);
	printf("pivot: %ld\n", call.p_min);
	s_tmp = size;
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
	if (call.ra > call.rb)
	{
		i = call.rb;
		while (i)
		{
			rotate_rrr(a, b);
			ft_putstr("rrr\n");
			i--;
		}
		while (i < call.ra - call.rb)
		{
			rotate_ab(a);
			ft_putstr("ra\n");
			i++;
		}
	}
	else
	{
		i = call.ra;
		while (i)
		{
			rotate_rrr(a, b);
			ft_putstr("rrr\n");
			i--;
		}
		while (i < call.rb - call.ra)
		{
			rotate_ab(b);
			ft_putstr("rb\n");
			i++;
		}
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
	if (size < 3)
		return ;
	call_init(&call);
	get_max_pivot(size, b, &call);
	get_min_pivot(size, b, &call);
	s_tmp = size;
	printf("pivot: %ld\n", call.p_max);
	printf("pivot: %ld\n", call.p_min);
	while (s_tmp)
	{
		if ((*b)->value <= call.p_min)
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
			if ((*b)->value <= call.p_max)
			{
				rotate_ab(a);
				ft_putstr("ra\n");
				call.ra++;
			}
		}
		s_tmp--;
	}
	sort_a_to_b(call.pb - call.ra, a, b);
	if (call.ra > call.rb)
	{
		i = call.rb;
		while (i)
		{
			rotate_rrr(a, b);
			ft_putstr("rrr\n");
			i--;
		}
		while (i < call.ra - call.rb)
		{
			rotate_ab(a);
			ft_putstr("ra\n");
			i++;
		}
	}
	else
	{
		i = call.ra;
		while (i)
		{
			rotate_rrr(a, b);
			ft_putstr("rrr\n");
			i--;
		}
		while (i < call.rb - call.ra)
		{
			rotate_ab(b);
			ft_putstr("rb\n");
			i++;
		}
	}
	sort_a_to_b(call.ra, a, b);
	sort_b_to_a(call.rb, a, b);
}