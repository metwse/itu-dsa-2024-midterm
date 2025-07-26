#ifndef Q1_2_H
#define Q1_2_H

typedef struct Node {
	char label;
	struct Node *next;
} NODE;


void add_to_list(NODE **list_head, char data);

NODE **adj_matrix_to_list(int **adj_matrix, int node_count, char *node_labels);

#endif
