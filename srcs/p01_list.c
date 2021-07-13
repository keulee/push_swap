#include "../includes/push_swap.h"

void	insert_node(t_node **node, int value)
{
	t_node *new;
	t_node *tmp;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_exit_msg("ERROR");
	tmp = *node;

	//init t_node new
	new->next = NULL;
	new->prev = NULL;
	new->value = value;

	//if there's no node.
	if (tmp == NULL)
	{
		*node = new;
		return ;
	}

	//find the last node in the linked list
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void		find_double(t_node *node, int value)
{
	while (node->next != NULL)
	{
		if (node->value == value)
			ft_exit_msg("ERROR: Value doubled");
		node = node->next; 
	}
}

/* swap ab
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
** sa and sb at the same time.
*/
void	swap_ss(t_node **a, t_node **b, int stack)
{
	swap_ab(a, stack);
	swap_ab(b, stack);
	if (stack == AB)
		ft_putstr("ss\n");
}

/*
** take the first element at the top of b and put it at the top of a. \
** Do nothing if b is empty.
*/
void	push_ab(t_node **dest, t_node **src, int stack)
{
	t_node *tmp;

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

/*
**  shift up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	rotate_ab(t_node **node, int stack)
{
	t_node *tmp;
	t_node *tmp2;

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
** ra and rb at the same time.
*/
void	rotate_rr(t_node **a, t_node **b, int stack)
{
	rotate_ab(a, stack);
	rotate_ab(b, stack);
	if (stack == AB)
		ft_putstr("rr\n");
}

/*
** shift down all elements of stack a by 1.
** The last element becomes the first one.
*/
void	rev_rotate_ab(t_node **node, int stack)
{
	t_node *tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->next = NULL; // bug?
	tmp->next = *node;
	tmp->prev = NULL;
	*node = tmp;
	(*node)->next->prev = tmp;
	if (stack == A)
		ft_putstr("rra\n");
	else if (stack == B)
		ft_putstr("rrb\n");
}

/*
** rra and rrb at the same time.
*/
void	rotate_rrr(t_node **a, t_node **b, int stack)
{
	rev_rotate_ab(a, stack);
	rev_rotate_ab(b, stack);
	if (stack == AB)
		ft_putstr("rrr\n");
}

int		get_listsize(t_node **a)
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