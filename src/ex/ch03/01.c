#include "../../utils/gcd.h"
#include <stdio.h>

#define MAX_X 100
#define MAX_Y 100

int arr[MAX_X][MAX_Y];

void print_array() {
	int i, j;
	for (i = 0; i < MAX_X; i++) {
		for (j = 0; j < MAX_Y; j++) {
			if (j != 0)
				printf(" ");
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int i, j;
	for (i = 1; i < MAX_X; i++) {
		for (j = 1; j < MAX_Y; j++) {
			if (gcd(i, j) == 1)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}

	print_array();
	return 0;
}
