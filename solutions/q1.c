#include "q1-2.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
	NODE *list_head = NULL;

	for (int i = 0; i < 10; i++) {
		add_to_list(&list_head, 'A' + i);
		printf("Pushing %c to list\n", 'A' + i);
	}

	printf("Iterating list: ");
	NODE *current = list_head;
	for (int i = 0; i < 10; i++) {
		printf("%c ", current->label);
		current = current->next;
	}
	printf("END OF LIST\n");

	return 0;
}
