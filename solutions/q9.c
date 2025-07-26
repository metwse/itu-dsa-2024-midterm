#include "q8-9.h"

#include <stdio.h>


int main()
{
	Node *tree = dummy_tree(5);

	printf("Node count of tree with depth 5: %d\n", count_nodes(tree));

	delete_leaves(&tree);

	printf("After deletion of leaves: %d\n", count_nodes(tree));
}
