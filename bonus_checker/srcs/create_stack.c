#include "../includes/checker.h"

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

void	value_check(char *str, t_info *info)
{
	int			i;
	int			neg;
	long long	arg;

	i = 0;
	neg = 1;
	arg = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			neg = neg * -1;
		if (str[i] == '\0' || str[i] == '0')
			ft_exit_msg("ERROR: Arguemnt not correct");
	}
	if (!ft_only_digit(&str[i]))
		ft_exit_msg("ERROR: Argument not int");
	if (str[i] == '0' && ft_digit(str[i + 1]))
		ft_exit_msg("ERROR");
	while (ft_digit(str[i]))
		arg = arg * 10 + (str[i++] - 48);
	if (neg == -1)
		arg *= -1;
	if (arg > 2147483647 || arg < -2147483648)
		ft_exit_msg("ERROR: int range not valid");
	info->arg = arg;
}

void	insert_node(t_node **node, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_exit_msg("ERROR");
	tmp = *node;
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	if (tmp == NULL)
	{
		*node = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	find_double(t_node *node, int value)
{
	while (node->next != NULL)
	{
		if (node->value == value)
			ft_exit_msg("ERROR");
		node = node->next;
	}
}

int	get_listsize(t_node **a)
{
	t_node	*tmp;
	int		size;

	tmp = *a;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
