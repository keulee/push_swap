#include "../includes/push_swap.h"

t_node	*creat_node()
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	return (new);
}

void	insert_value(t_node **node, int value)
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

void	swap_ab(t_node **node)
{
	int	tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node)->value;
	(*node)->value = (*node)->next->value;
	(*node)->next->value = tmp;
}

void	swap_ss(t_node **a, t_node **b)
{
	swap_ab(a);
	swap_ab(b);
}

void	push_ab(t_node **dest, t_node **src)
{
	t_node *tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	(*dest)->prev = tmp;
	*dest = tmp;
}

// void	rotate_ab(t_node **a)
// {
// 	t_node *tmp;

// 	tmp = 
// }