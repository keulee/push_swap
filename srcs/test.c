int	check(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		find_same_arg(--)
{
	char **arg;
	char *array;
	int i;
	int j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (check(array, arg[i]) == 0)
		{
			array[j] = arg[i];
			j++;
		}
		else //when check returns 1
			exit_msg("ERROR: Argument must not be doubled");
		i++;
	}

}