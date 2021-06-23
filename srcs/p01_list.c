#include "../includes/push_swap.h"

void	insert_value(t_node **node, int value)
{
	t_node *new;
	t_node *tmp;

	new = (t_node *)malloc(sizeof(t_node));
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

void		print_node_a(t_node *node)
{
	int i;

	i = 0;
	if (node == NULL)
	{
		printf("[node a empty]\n");
		return ;
	}
	while (node != NULL)
	{
		printf("[%d] : %d\n", i, node->value);
		node = node->next;
		i++;
	}
	printf("---------\n");
	printf(" node a\n");

}

void		print_node_b(t_node *node)
{
	int i;

	i = 0;
	if (node == NULL)
	{
		printf("[node b empty]\n");
		return ;
	}
	while (node != NULL)
	{
		printf("[%d] : %d\n", i, node->value);
		node = node->next;
		i++;
	}
	printf("---------\n");
	printf(" node b\n");

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
	// tmp = *src;
	// *dest = tmp;
	// (*dest)->prev = tmp;
	// free((*src)->next);
	// (*src)->next->prev = NULL;	
	// if ((*dest)->prev == NULL)
	// {
		// (*src)->value = (*src)->value;
		// new->next = *dest;
		// (*dest)->prev = new;
	// }
	tmp = *src;
	tmp->next = *dest;
	(*dest)->prev = tmp;
	// free((*src)->next->prev);
	// free(*src);
	(*src)->next->prev = NULL;  

}