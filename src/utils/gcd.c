#include "gcd.h"

int gcd(int u, int v) {
	int t;
	if (u == 0 && v == 0)
		return 0;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}
