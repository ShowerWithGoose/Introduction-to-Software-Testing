#include <stdio.h>
#include <string.h>

int main() {
	char a[2048];
	gets(a);
	int b = 0, m, t, p, c = 0, d = 0;
	m = strlen(a);
	for (b = 0; b < m; b++) {
		c = 0, d = 0;
		if (a[b] == '-') {
			if (a[b - 1] >= 'a' && a[b] == '-' && a[b + 1] <= 'z' && a[b - 1] <= a[b + 1]) {
				t = a[b - 1];
				p = a[b + 1];
				c = 1;
				for (t; t < p - 1; t++)
					printf("%c", t + 1);
			}
			if (a[b - 1] >= 'A' && a[b] == '-' && a[b + 1] <= 'Z' && a[b - 1] <= a[b + 1]) {
				t = a[b - 1];
				p = a[b + 1];
				d = 1;
				for (t; t < p - 1; t++)
					printf("%c", t + 1);
			}
			if (a[b - 1] >= '0' && a[b] == '-' && a[b + 1] <= '9' && a[b - 1] <= a[b + 1]) {
				t = a[b - 1];
				p = a[b + 1];
				c = 0, d = 0;
				for (t; t < p - 1; t++)
					printf("%c", t + 1);
			} else {
				if (c == 0 && d == 0)
					printf("-");
			}

		} else
			printf("%c", a[b]);

	}
	return 0;
}



