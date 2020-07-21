#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char *data;
	struct s_list *next;
}				t_list;

t_list *create_node(char *data, size_t dsize);
void delete_node(t_list **node);
t_list *remove_node(t_list *head, t_list *node);
//t_list *create_list(int size);
t_list *add_node(t_list *list,t_list *node);
t_list *append_node(t_list *list, t_list *node);
t_list *get_node_by_data(t_list *list, char *data);
void	delete_list(t_list **list);

#endif
