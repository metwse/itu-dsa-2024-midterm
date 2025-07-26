#ifndef Q3_5_H
#define Q3_5_H

typedef struct node {
	int size;
	struct node *next;
	struct node *prev;
} Node;

typedef struct {
	Node *first;
	Node *last;
	int len;
} Pancakes;


void flip(Pancakes *, int k);

void bubble_sort(Pancakes *);

Pancakes *dummy_list();

#endif
