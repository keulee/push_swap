#include "../includes/push_swap.h"

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
	while (ft_digit(str[i]))
	{
		arg = arg * 10 + (str[i] - 48);
		i++;
	}
	if (neg == -1)
		arg *= -1;
	if (arg > 2147483647 || arg < -2147483648)
		ft_exit_msg("ERROR: int range not valid");
	info->arg = arg;
}
