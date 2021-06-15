#include "../includes/push_swap.h"

int		check_double(char **s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (ft_strcmp(s1[i], s2) == 0) //if two string is the same, it returns 0
			return (0);
		i++;
	}
	return (i);
}

int	count_arg(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

void	value_check(char *str, t_info *info)
{
	int i;

	i = 0;
	if (ft_strncmp(&str[i], "-", 1) == 0)
		info->neg = 1;
	if (info->neg == 1)
	{
		i++;
		if (str[i] == '\0')
			ft_exit_msg("ERROR: Arguemnt not int");
	}
	if (!ft_only_digit(&str[i]))
		ft_exit_msg("ERROR: Argument not int");
}