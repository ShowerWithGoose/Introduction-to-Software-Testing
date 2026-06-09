#include <stdio.h>
#include <string.h>

int main() {
	int x, y, z;
	char a, b, c;
	int i = 1;
	x = 0;
	a = '+';
	while (i != 0) {
		scanf("%d %c", &y, &b);
		if (b == '*' || b == '/') {
			while (b == '*' || b == '/') {
				scanf("%d %c", &z, &c);
				if (b == '*') {
					y = y * z;
				} else {
					y = y / z;
				}
				b = c;
			}
		}
		x = a == '+' ? x + y : x - y;
		a = b;
		if (a == '=') {
			printf("%d\n", x);
			i = 0;
		}
	}
	return 0;
}
