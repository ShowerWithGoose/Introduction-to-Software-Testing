#include <stdio.h>

struct stack {
	int top;
	int num[1020];
};
struct stack s;

int main() {
	s.top = 0;
	int n, x;
	while (scanf("%d", &n) && n != -1) {
		if (n == 1) {
			scanf("%d", &x);
			if (s.top >= 100) {
				printf("error ");
			} else {
				s.num[s.top++] = x;
			}
		} else if (n == 0) {
			if (s.top < 1) {
				printf("error ");
			} else {
				printf("%d ", s.num[(s.top--) - 1]);
			}
		}
	}
	return 0;
}
