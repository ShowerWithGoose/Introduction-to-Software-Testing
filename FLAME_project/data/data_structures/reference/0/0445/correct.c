#include <stdio.h>
#include <string.h>
char a[100000], b[100], c[100000];
int main() {
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '-') {
			if (a[i - 1] < a[i + 1] && (('a' <= a[i - 1] && a[i + 1] <= 'z') || ('A' <= a[i - 1] && a[i + 1] <= 'Z') || ('0' <= a[i - 1] && a[i + 1] <= '9'))) {
			
				strcpy(c, &a[i + 1]);
				c[strlen(a) - (i + 1)] = '\0';
				int j;
				for (j = 0; j < (a[i + 1] - a[i - 1]); j++) {
					b[j] = a[i - 1] + j;
			}
				b[j] = '\0';
				a[i - 1] = '\0';
				strcat(a, b);
				strcat(a, c);
				i--;
			}
		}
	}
	printf("%s", a);
	return 0;
}

