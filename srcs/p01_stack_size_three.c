#include "../includes/push_swap.h"

void		stack_size_three(int size, t_node **a)
{
	long	max;
	
	max = get_max(size, a);
	printf("max nbr : %ld\n", max);
	if (size == 2)
	{
		if ((*a)->value == max)
			swap_ab(a, A);
		else
			return ;
	}
	if (size == 3)
	{

	}
}