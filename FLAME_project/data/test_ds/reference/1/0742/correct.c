#include <stdio.h>
#include <string.h>

char s[1000], u[1000], e[1000], y[1000], i;
int a, b, c, d, o[1000], h[1000], k, n;


int main() {
	gets(s);
	a = strlen(s);
	for (b = 0; s[b]; b++) {
		if (s[b] != '-') {
			e[d] = s[b];
			d++;
		} else {
			if (s[b + 1] > s[b - 1]  && ((s[b + 1] <= 'z' && s[b + 1] >= 'a' && s[b - 1] <= 'z'
			                              && s[b - 1] >= 'a') || (s[b + 1] <= 'Z' && s[b + 1] >= 'A' && s[b - 1] <= 'Z' && s[b - 1] >= 'A'
			                                                     ) || (s[b + 1] <= '9' && s[b + 1] >= '0' && s[b - 1] <= '9' && s[b - 1] >= '0'))) {
				i = s[b - 1] + 1;
				while (i != s[b + 1]) {
					e[d] = i++;
					d++;
				}

			} else
				e[d++] = '-';
		}
	}
	printf("%s", e);
	return 0;
}


