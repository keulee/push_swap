#include "../includes/push_swap.h"

t_node	*creat_node()
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	return (new);
}

void	insert_node(t_node **node, int value)
{
	t_node *new;
	t_node *tmp;

	// new = (t_node *)malloc(sizeof(t_node));
	new = creat_node();
	tmp = *node;

	//init t_node new
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	
	// printf("value in node : %d\n", value);

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
void	swap_ab(t_node **node)
{
	int	tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node)->value;
	(*node)->value = (*node)->next->value;
	(*node)->next->value = tmp;
}

/*
** sa and sb at the same time.
*/
void	swap_ss(t_node **a, t_node **b)
{
	swap_ab(a);
	swap_ab(b);
}


/*
** take the first element at the top of b and put it at the top of a. \
** Do nothing if b is empty.
*/
void	push_ab(t_node **dest, t_node **src)
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
}

/*
**  shift up all elements of stack a by 1.
** The first element becomes the last one.
*/
void	rotate_ab(t_node **a)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = *a;
	*a = tmp->next;
	tmp2 = *a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	tmp->prev = tmp2;
}