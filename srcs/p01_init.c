#include "../includes/push_swap.h"

void	ft_init(t_info *info)
{
	info->i = 1;
	info->j = 0;
	info->tmp = NULL;
	info->stack_a = NULL;
	info->stack_b = NULL;
	info->arg = 0;
	info->listsize= 0;
	info->ra = 0;
	info->pb = 0;
	info->rb = 0;
	info->pa = 0;
}