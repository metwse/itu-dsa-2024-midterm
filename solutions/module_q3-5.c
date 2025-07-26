#include "q3-5.h"

#include <stdlib.h>


void flip(Pancakes *p, int k)
{
	Node *n = p->first;
	Node *hold;

	for (int i = 0; i < k; i++) {
		hold = n->next;
		n->next = n->prev;
		n->prev = hold;
		n = hold;
	}

	if (n) {
		hold = p->first;
		p->first = n->prev;
		n->prev = hold;
		hold->next = n;
		p->first->prev = NULL;
	} else {
		hold = p->first;
		p->first = p->last;
		p->last = hold;
	}
}

void bubble_sort(Pancakes *b)
{
	for (int i = 0; i < b->len; i++) {
		Node *n = b->first;

		for (int j = 0; j < b->len - i - 1; j++) {
			if (n->size > n->next->size) {
				int hold = n->size;
				n->size = n->next->size;
				n->next->size = hold;
			}
			n = n->next;
		}
	}
}

// Generates a dummy doubly-linked list with 10 elements. Used for testing.
Pancakes *dummy_list()
{
	Pancakes *p = malloc(sizeof(Pancakes));

	Node *prev = NULL, *new;
	for (int i = 0; i < 10; i++) {
		new = malloc(sizeof(Node));

		new->prev = prev;
		if (prev == NULL)
			p->first = new;
		else
			prev->next = new;
		prev = new;
	}
	new->next = NULL;
	p->last = new;
	p->len = 10;

	return p;
}
