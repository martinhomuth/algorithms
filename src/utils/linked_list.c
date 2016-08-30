#include "linked_list.h"
#include <stdlib.h>

struct node *z;

void list_initialize() {
	head = malloc(sizeof *head);
	z = malloc(sizeof *z);
	head->next = z;
	z->next = z;
}

void delete_next(struct node *t) {
	struct node *tmp = t->next;
	t->next = t->next->next;
	free(tmp);
}

struct node *insert_after(int v, struct node *t) {
	struct node *x;
	x = malloc(sizeof *x);
	x->key = v;
	x->next = t->next;
	t->next = x;
	return x;
}

void  move_next_to_front(struct node *t) {
	struct node *ptr = t;
	ptr = t->next;
	t->next = ptr->next;
	ptr->next = head->next;
	head->next = ptr;
}


#ifdef TEST

#include <assert.h>
#include <stdio.h>

void test_empty_list() {
	list_initialize();
	assert(head->next == z);
	assert(z->next == z);
	printf("+");
}

void test_order() {
	struct node *item1, *item2, *item3, *ptr;
	list_initialize();
	item1 = insert_after(1, head);
	item2 = insert_after(2, item1);
	item3 = insert_after(3, item2);
	ptr = head;
	assert(ptr->next == item1);
	ptr = ptr->next;
	assert(ptr->key == 1);
	assert(ptr->next == item2);
	ptr = ptr->next;
	assert(ptr->key == 2);
	assert(ptr->next == item3);
	printf("+");
}

void test_move_next_to_front() {
	struct node *item1, *item2, *item3, *ptr;
	list_initialize();
	item1 = insert_after(1, head);
	item2 = insert_after(2, item1);
	item3 = insert_after(3, item2);
	move_next_to_front(item2);
	ptr = head;
	assert(ptr->next == item3);
	ptr = ptr->next;
	assert(ptr->key == 3);
	assert(ptr->next == item1);
	ptr = ptr->next;
	assert(ptr->key == 1);
	assert(ptr->next == item2);
	printf("+");
}

int main(int argc, char *argv[]) {
	printf("Testing %s\nTests: ", __FILE__);
	test_empty_list();
	test_order();
	test_move_next_to_front();
	printf("\n");
	return 0;
}

#endif
