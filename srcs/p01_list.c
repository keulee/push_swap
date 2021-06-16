#include "../includes/push_swap.h"

// void	init_list(t_list *list)
// {
// 	list = (t_list *)malloc(sizeof(t_list));
// 	if (!list)
// 		ft_exit_msg("ERROR: List malloc failed");
// 	else
// 	{
// 		list->tail = NULL;
// 		list->count = 0;
// 	}
// }

// void	add_value(t_list *list, int count, int value)
// {
// 	int i;
// 	t_node *new = (t_node*)malloc(sizeof(t_node));
// 	new->value = value;

// 	printf("value in node : %d\n", value);

// 	i = 0;
// 	if (list->count == 0)
// 	{
// 		list->tail = new;
// 		new->next = new;
// 		new->prev = new;
// 	}
// 	else
// 	{
// 		while (i < count)
// 		{
// 			list->tail = list->tail->next;
// 			i++;
// 		}
// 		new->next = list->tail->next;
// 		new->prev = list->tail;
// 		list->tail->next = new;
// 		new->next->prev = new;
// 		if (list->count == count)
// 			list->tail = new;
// 		list->count++;
// 	}
// }

void	insert_value(t_node **node, int value)
{
	t_node *new;
	t_node *tmp;

	new = (t_node *)malloc(sizeof(t_node));
	tmp = *node;

	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	
	printf("value in node : %d\n", value);

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