#include "q3-5.h"

#include <stdio.h>


// Tests flip function.
int main()
{
	Pancakes *p = dummy_list();

	printf("Before sorting: ");
	Node *n = p->first;
	for (int i = 0; i < p->len; i++) {
		printf("%d ", p->len - i);
		n->size = p->len - i;
		n = n->next;
	}
	printf("\n");

	bubble_sort(p);

	printf("After bubble_sort: ");
	n = p->first;
	for (int i = 0; i < p->len; i++) {
		printf("%d ", n->size);
		n = n->next;
	}
	printf("\n");
}
