#include "q3-5.h"

#include <stdio.h>


// Tests flip function.
int main()
{
	Pancakes *p = dummy_list();

	printf("Before flipping: ");
	Node *n = p->first;
	for (int i = 0; i < p->len; i++) {
		printf("%d ", i);
		n->size = i;
		n = n->next;
	}
	printf("\n");

	flip(p, 5);
	flip(p, 7);

	printf("After flipping at index 5 and 7: ");
	n = p->first;
	for (int i = 0; i < p->len; i++) {
		printf("%d ", n->size);
		n = n->next;
	}
	printf("\n");

	flip(p, 10);
	printf("After flipping at index 10: ");
	n = p->first;
	for (int i = 0; i < p->len; i++) {
		printf("%d ", n->size);
		n = n->next;
	}
	printf("\n");
}
