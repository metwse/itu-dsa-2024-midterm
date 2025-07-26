#include "q1-2.h"

#include <stdlib.h>


void add_to_list(NODE **list_head, char data)
{
	if (*list_head == NULL) {
		*list_head = malloc(sizeof(NODE));
		(*list_head)->label = data;
		(*list_head)->next = NULL;
	} else {
		NODE *current = *list_head;
		while (current->next)
			current = current->next;

		NODE *new = malloc(sizeof(NODE));
		new->label = data;
		new->next = NULL;

		current->next = new;
	}
}

NODE **adj_matrix_to_list(int **adj_matrix, int node_count, char *node_label)
{
	NODE **list = malloc(sizeof(NODE *) * node_count);

	for (int i = 0; i < node_count; i++) {
		list[i] = NULL;

		for (int j = 0; j < node_count; j++) {
			if (adj_matrix[i][j])
				add_to_list(&list[i], node_label[j]);
		}
	}

	return list;
}
