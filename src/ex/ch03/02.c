#include "../../utils/linked_list.h"
#include <assert.h>
#include <stdio.h>

/*
 * this file only tests move_next_to_front as it is now part of
 * linked_list
 */
int main() {
	struct node *item1, *item2, *item3;
	list_initialize();
	item1 = insert_after(1, head);
	item2 = insert_after(2, item1);
	item3 = insert_after(3, item2);
	move_next_to_front(item2);
	assert(item3->next == item1);
	assert(item1->next == item2);
	assert(item2->next != item3);
	printf("all nice\n");
	return 0;
}
