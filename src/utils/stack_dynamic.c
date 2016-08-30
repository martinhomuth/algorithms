#include "stack.h"
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


#ifdef TEST

#include <assert.h>

/*
 * Two simple tests:
 *     - order preserved
 *     - unable to pop more than pushed
 */
void test_order_preserved() {
	stackinit();
	push(2);
	push(4);
	assert(pop() == 4);
	assert(pop() == 2);
	printf("+");
}

void test_lower_bound() {
	stackinit();
	push(3);
	assert(pop() == 3);
	assert(pop() == 0);
	printf("+");
}

int main(int argc, char *argv[]) {
	printf("Testing %s\n\nTests: ", __FILE__);
	test_order_preserved();
	test_lower_bound();
	printf("\n");
	return 0;
}

#endif
