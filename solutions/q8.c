#include "q8-9.h"

#include <stdio.h>


int main()
{
	int depth;

	printf("Enter tree depth: ");
	if (scanf("%d", &depth) != 1)
		return 1;

	Node *tree = dummy_tree(depth);

	printf("Node count of tree with depth %d: %d\n",
	       depth, count_nodes(tree));
}
