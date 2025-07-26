#ifndef Q8_9_H
#define Q8_9_H

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;


void delete_leaves(Node **);

int count_nodes(Node *);

Node *dummy_tree(int depth);

#endif
