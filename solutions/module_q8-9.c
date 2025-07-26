#include "q8-9.h"

#include <stdlib.h>


int count_nodes(Node *n)
{
	int c = 1;
	if (n->left)
		c += count_nodes(n->left);
	if (n->right)
		c += count_nodes(n->right);
	return c;
}

void delete_leaves(Node **n)
{
	if ((*n)->left || (*n)->right) {
		if ((*n)->left)
			delete_leaves(&(*n)->left);
		if ((*n)->right)
			delete_leaves(&(*n)->right);
	} else {
		free(*n);
		*n = NULL;
	}
}

Node *dummy_tree(int depth)
{
	Node *n = malloc(sizeof(Node));

	if (depth > 1) {
		n->left = dummy_tree(depth - 1);
		n->right = dummy_tree(depth - 1);
	}

	return n;
}
