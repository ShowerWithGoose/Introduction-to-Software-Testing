#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char a[10000];
	int i, j, c;
	scanf("%s", a);
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] != '-')
			printf("%c", a[i]);
		else if (a[i] == '-') {
			if (islower(a[i - 1]) && islower(a[i + 1])) {
				for (j = 1; a[i - 1] + j < a[i + 1]; j++)
					printf("%c", a[i - 1] + j);

			}	else if ( isupper(a[i - 1]) && isupper(a[i + 1])) {
				for (j = 1; a[i - 1] + j < a[i + 1]; j++)
					printf("%c", a[i - 1] + j);

			} else	if (isdigit(a[i - 1]) && isdigit(a[i + 1])) {
				for (j = 1; a[i - 1] + j < a[i + 1]; j++)
					printf("%c", a[i - 1] + j);

			} else
				printf("-");
		}
	}
	return 0;
}
