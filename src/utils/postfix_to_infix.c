/**
 * Converts a fully bracketed infix-statement into a
 * postfix statement.
 */
#include "stack.h"
#include <stdio.h>

/**
 * TODO: * Allow spaces between operands, brackets and operators
 *       * error handling of the inputs
 */

int main() {
	char c;
	for (stackinit(); scanf("%1s", &c) != EOF;) {
		if (c == ')') printf("%1c", (char) pop());
		if (c == '+') push((int) c);
		if (c == '*') push((int) c);
		while (c >= '0' && c <= '9') {
			printf("%1c", c);
			scanf("%1c", &c);
		}
		if (c == '(') printf(" ");
	}
	printf("\n");
	return 0;
}
