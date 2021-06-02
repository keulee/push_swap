#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		ft_exit_msg("ERROR: Argument not enough");
	else
	{
		while (i < ac)
		{
			printf("%s\n", av[i]);
			
			i++;
		}
	}
	return (0);
}
