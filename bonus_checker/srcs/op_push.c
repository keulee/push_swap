#include "../includes/checker.h"

/*
** pa, pb (push a, push b)
** take the first element at the top of b and put it at the top of a. \
** Do nothing if b is empty.
*/
void	push_ab(t_node **dest, t_node **src, int stack)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = tmp;
	*dest = tmp;
	if (stack == A)
		ft_putstr("pa\n");
	else if (stack == B)
		ft_putstr("pb\n");
}
