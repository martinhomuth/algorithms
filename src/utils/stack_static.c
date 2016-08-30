#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

static int stack[MAX+1], p;

void stackinit() {
	p = 0;
}

void push(int v) {
	if (p < MAX)
		stack[p++] = v;
}

int pop() {
	if (stackempty())
		return 0;
	else
		return stack[--p];
}

int stackempty() {
	return !p;
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

void test_upper_bound() {
	int i;
	stackinit();
	for (i = 0; i < MAX; i++)
		push(i);
	push(++i);
	assert(pop() != i);
	printf("+");
}

int main(int argc, char *argv[]) {
	printf("Testing %s\nTests: ", __FILE__);
	test_order_preserved();
	test_lower_bound();
	test_upper_bound();
	printf("\n");
	return 0;
}

#endif
