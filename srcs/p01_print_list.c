#include "../includes/push_swap.h"

void		print_node(t_node *node)
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
}

void		print_node_a(t_node *node, t_info *info)
{
	int i;

	i = 0;
	if (node == NULL)
	{
		printf("[node a empty]\n");
		return ;
	}
	// while (node != NULL)
	while (i < info->listsize)
	{
		printf("[%d] : %d\n", i, node->value);
		printf("- \n value = %d \n prev = %p \n next = %p \n - \n", node->value, node->prev, node->next);
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