#include "stack.h"
#include <stdio.h>

int main() {
	char c;
	int x;
	for (stackinit(); scanf("%1s", &c) != EOF; ) {
		x = 0;
		if (c == '+') x = pop() + pop();
		if (c == '*') x = pop() * pop();
		while (c >= '0' && c <= '9') {
			x = 10 * x + (c - '0');
			scanf("%1c", &c);
		}
		push(x);
	}
	printf("%d\n", x);
	return 0;
}
