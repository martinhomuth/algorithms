#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

struct node {
	int key;
	struct node *next;
};

void list_initialize();
void delete_next(struct node *t);
struct node *insert_after(int v, struct node *t);
void move_next_to_front(struct node *t);

#endif
