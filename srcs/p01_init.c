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
}

void	call_init(t_call *call)
{
	call->pa = 0;
	call->pb = 0;
	call->ra = 0;
	call->rb = 0;
}