#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *next;
};

static struct node *head, *z, *t;

void stackinit() {
	head = malloc(sizeof *head);
	z = malloc(sizeof *z);
	head->next = z;
	head->key = 0;
	z->next = z;
}

void push(int v) {
	t = malloc(sizeof *t);
	t->key = v;
	t->next = head->next;
	head->next = t;
}

int pop() {
	int x;
	t = head->next;
	head->next = t->next;
	x = t->key;
	free(t);
	return x;
}

int stackempty() {
	return head->next == z;
}
