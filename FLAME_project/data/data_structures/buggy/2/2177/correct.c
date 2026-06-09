#include <stdio.h>
#include <string.h>

int main () {
	int a1, a2, a3, a4;
	char b1, b2, b3, b4;
	scanf("%d %c", &a1, &b1);
	while (b1 == '*' || b1 == '/') {
		scanf("%d %c", &a3, &b3);
		if (b1 == '*')
			a1 *= a3;
		else if (b1 == '/')
			a1 /= a3;
		b1 = b3;
	}
	while (b1 == '+' || b1 == '-') {
		scanf("%d %c", &a2, &b2);
		while (b2 == '*' || b2 == '/') {
			scanf("%d %c", &a4, &b4);
			if (b2 == '*')
				a2 *= a4;
			else if (b2 == '/')
				a2 /= a4;
			b2 = b4;
		}
		if (b1 == '+')
			a1 += a2;
		else if (b1 == '-')
			a1 -= a2;
		b1 = b2;
	}
	printf("%d", a1);
	return 0;
}


