#include "../includes/push_swap.h"

/* 
** sa, sb (swap a, swap b)
** swap the first 2 elements at the top of stack a(or b).
** Do nothing if there is only one or no elements).
*/
void	swap_ab(t_node **node, int stack)
{
	int	tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node)->value;
	(*node)->value = (*node)->next->value;
	(*node)->next->value = tmp;
	if (stack == A)
		ft_putstr("sa\n");
	else if (stack == B)
		ft_putstr("sb\n");
}

/*
** ss
** sa and sb at the same time.
*/
void	swap_ss(t_node **a, t_node **b, int stack)
{
	swap_ab(a, stack);
	swap_ab(b, stack);
	if (stack == AB)
		ft_putstr("ss\n");
}
