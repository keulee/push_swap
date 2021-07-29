#include "../includes/push_swap.h"

void	create_stack(t_info *info, char **av)
{
	while (av[info->i])
	{
		info->tmp = ft_split(av[info->i], ' ');
		info->j = 0;
		while (info->tmp[info->j])
		{
			value_check(info->tmp[info->j], info);
			insert_node(&info->stack_a, info->arg);
			find_double(info->stack_a, info->arg);
			info->listsize++;
			info->j++;
		}
		ft_free_tab2(info->tmp);
		info->i++;
	}
}
