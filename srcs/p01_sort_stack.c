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
	printf("-- operating a to b in --\n");
	printf("size = %d\n", size);
	if (size <= 3)
	{
		// stack_a_three(size, a, &call);
		// swap_ab(a, A);
		return ;

	}
	call_init(&call);
	get_pivot(size, a, &call);
	printf("big pivot in a: %ld\n", call.p_big);
	printf("small pivot in a: %ld\n", call.p_small);
	s_tmp = size;
	// printf("ra: %d\n", call.ra);
	// printf("rb: %d\n", call.rb);
	// printf("pa: %d\n", call.pa);
	// printf("pb: %d\n", call.pb);
	while (s_tmp--)
	{
		if ((*a)->value >= call.p_big)
		{
			rotate_ab(a, A);
			call.ra++;
		}
		else
		{
			push_ab(b, a, B);
			call.pb++;
			if ((*b)->value >= call.p_small)
			{
				rotate_ab(b, B);
				call.rb++;
			}
		}
	}
	printf("ra: %d\n", call.ra);
	printf("rb: %d\n", call.rb);
	printf("pa: %d\n", call.pa);
	printf("pb: %d\n", call.pb);
	// print_node_a(*a);
	// print_node_b(*b);
	if (call.ra > call.rb)
	{
		i = call.rb;
		while (0 < i)
		{
			rotate_rrr(a, b, AB);
			// rev_rotate_ab(b, B);
			i--;
		}
		while (i < call.ra - call.rb)
		{
			rev_rotate_ab(a, A);
			i++;
		}
	}
	else
	{
		i = call.ra;
		while (i)
		{
			rotate_rrr(a, b, AB);
			i--;
		}
		while (i < call.rb - call.ra)
		{
			rev_rotate_ab(b, B);
			i++;
		}
	}
	printf("-- operating a to b  --\n");
	print_node_a(*a);
	print_node_b(*b);
	printf("-----------------------\n");
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
	printf("-- operating b to a in --\n");
	printf("size = %d\n", size);
	if (size < 3)
	{
		// push_ab(a, b, A);
		// push_ab(a, b, A);
		return ;
	}
	call_init(&call);
	get_pivot(size, b, &call);
	s_tmp = size;
	printf("big pivot in b: %ld\n", call.p_big);
	printf("small pivot in b: %ld\n", call.p_small);
	while (s_tmp)
	{
		if ((*b)->value < call.p_small)
		{
			rotate_ab(b, B);
			call.rb++;
		}
		else
		{
			push_ab(a, b, A);
			call.pa++;
			// if ((*b)->value < call.p_big)
			if ((*a)->value < call.p_big)
			{
				rotate_ab(a, A);
				call.ra++;
			}
		}
		s_tmp--;
	}
	sort_a_to_b(call.pa - call.ra, a, b);
	if (call.ra > call.rb)
	{
		i = call.rb;
		while (i)
		{
			rotate_rrr(a, b, AB);
			i--;
		}
		while (i < call.ra - call.rb)
		{
			rev_rotate_ab(a, A);
			i++;
		}
	}
	else
	{
		i = call.ra;
		while (i)
		{
			rotate_rrr(a, b, AB);
			i--;
		}
	}
	printf("-- operating b to a --\n");
	print_node_a(*a);
	print_node_b(*b);
	printf("-----------------------\n");
	sort_a_to_b(call.ra, a, b);
	sort_b_to_a(call.rb, a, b);
}