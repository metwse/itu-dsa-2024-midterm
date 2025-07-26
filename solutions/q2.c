#include "q1-2.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Test function to validate the `adj_matrix_to_list` implementation. `memcpy`
// used for heap allocating `adj_matrix`, it has required as function
// accepts `int **`.
int main()
{
	int node_count = 5;
	char node_labels[5] = { 'A', 'B', 'C', 'D', 'E' };
	int **adj_matrix = malloc(sizeof(int *) * 5);

	for (int i = 0; i < node_count; i++)
		adj_matrix[i] = malloc(sizeof(int) * 5);
	memcpy(adj_matrix[0], (int[5]) {0, 0, 0, 1, 0}, sizeof(int) * 5);
	memcpy(adj_matrix[1], (int[5]) {0, 0, 1, 0, 1}, sizeof(int) * 5);
	memcpy(adj_matrix[2], (int[5]) {0, 1, 1, 1, 0}, sizeof(int) * 5);
	memcpy(adj_matrix[3], (int[5]) {0, 0, 0, 0, 0}, sizeof(int) * 5);
	memcpy(adj_matrix[4], (int[5]) {0, 0, 1, 0, 0}, sizeof(int) * 5);

	NODE **list = adj_matrix_to_list(adj_matrix, node_count, node_labels);

	for (int i = 0; i < node_count; i++) {
		NODE *current = list[i];
		if (current == NULL) {
			printf("[%d]: NULL\n", i);
			continue;
		}
		printf("[%d]: ", i);
		do
			printf("%c ", current->label);
		while ((current = current->next));

		printf("\n");
	}

	return 0;
}
