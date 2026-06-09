#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int bx[107], by[107], ex[107], ey[107], big = 0, temp = 0, n, begin, y;

void find(int x) {
	if (temp == 0) {
		y = x;
	}
	for (int i = 0; i < n; i++) {
		if (i != x && ex[x] == bx[i] && ey[x] == by[i]) {
			temp++;
			return find(i);
		}
	}
	if (temp > big) {
		big = temp;
		begin = y;
		temp = 0;
		return;
	} else {
		temp = 0;
		return;
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &bx[i], &by[i], &ex[i], &ey[i]);
	}
	for (i = 0; i < n; i++) {
		find(i);
	}
	printf("%d %d %d", big + 1, bx[begin], by[begin]);
	return 0;
}

