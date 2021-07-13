#include "../includes/push_swap.h"

void		stack_size_three(int size, t_node *a)
{
	long	max;
	
	max = get_max(size, &a);
	printf("max nbr : %ld\n", max);
}