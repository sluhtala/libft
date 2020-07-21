#include "ft_list.h"

t_list *create_node(char *data, size_t dsize)
{
	t_list *node;

	node = malloc(sizeof(t_list) + 1);
	bzero(node, dsize + 1);
	if (!(node->data = (char*)malloc(dsize)))
		return (NULL);
	node->data = memcpy(node->data, data, dsize);
	node->next = NULL;
	return (node);
}

void delete_node(t_list **node)
{
	t_list *temp;

	if (!node)
		return ;
	temp = *node;
	if (temp != NULL && temp->data)
		free(temp->data);
	free(*node);
	*node = NULL;
}

t_list *remove_node(t_list *head, t_list *node)
{
	t_list *temp;
	temp = head;
	if (!node || !head)
		return (head); 
	if (head == node)
	{
		head = head->next;
		delete_node(&node);
		return (head);
	}
	while (temp->next != node && temp)
	{
		temp = temp->next; 
	}
	temp->next = node->next;
	delete_node(&node);
	return (head);
}

/*
t_list *create_list(int size)
{
	t_list *list;
	t_list *temp;
	t_list *prev;
	int i;
	char *names[] = {"sasu","hellu","miika","joku"};
	i = 1;
	list = create_node(names[0], sizeof(char) * strlen(names[0]));
	prev = list;
	while (i < size)
	{
		temp = create_node(names[i%4], sizeof(char) * strlen(names[i%4]));
		prev->next = temp;
		prev = temp;
		i++;
	}
	return (list);
}
*/
t_list *add_node(t_list *list,t_list *node)
{
	if (!node)
		return (NULL);
	node->next = list;
	return (node);
}

t_list *append_node(t_list *list, t_list *node)
{
	t_list *temp;

	temp = list;
	if (temp == NULL)
		return (node);
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;
	return (list);
}

t_list *get_node_by_data(t_list *list, char *data)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (strcmp(list->data, data) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

void	delete_list(t_list **list)
{
	t_list *prev;
	t_list *temp;

	temp = *list;
	while (temp)
	{
		prev = temp;
		temp = temp->next;
		delete_node(&prev);
	}
	*list = NULL;
}
/*
int	main()
{
	t_list *list = NULL;

	//list = create_node("sasu", sizeof(char) * 4);
	list = create_list(100);
	//list = add_node(list, create_node("haamu", 5));	
	list = add_node(list, create_node("kissa", 5));
	list = append_node(list, create_node("donitsi", 7));	
	list = remove_node(list, get_node_by_data(list, "miika"));
	print_list(list);
	delete_list(&list);
	return (0);
}*/
