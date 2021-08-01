#include "../includes/push_swap.h"

/*
** ra, rb (rotate a, rotate b)
** shift up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	rotate_ab(t_node **node, int stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	*node = tmp->next;
	tmp2 = *node;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	tmp->prev = tmp2;
	if (stack == A)
		ft_putstr("ra\n");
	else if (stack == B)
		ft_putstr("rb\n");
}

/*
** rr
** ra and rb at the same time.
*/
void	rotate_rr(t_node **a, t_node **b, int stack)
{
	rotate_ab(a, stack);
	rotate_ab(b, stack);
	if (stack == AB)
		ft_putstr("rr\n");
}
