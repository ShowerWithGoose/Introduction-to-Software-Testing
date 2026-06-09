#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[150];
int spot = -1, num = -1;

int main() {
	fgets(a, 149, stdin);
	int l = strlen(a);
	for (int i = 0; i < l; i++) {
		if (a[i] != '0' && a[i] != '.' && num == -1)
			num = i;
		if (a[i] == '.')
			spot = i;
	}
	if (a[0] != '0')
		num++;
	int idx = spot - num;
	if (a[0] == '0') {
		printf("%c", a[num]);
		if (num + 2 != l)
			printf(".");
		for (int i = num + 1; i < l - 1; i++) {
			printf("%c", a[i]);
		}
		printf("e%d", idx);
	} else {
		printf("%c.", a[num - 1]);
		for (int i = num ; i < l - 1; i++) {
			if (a[i] != '.')
				printf("%c", a[i]);
		}
		printf("e%d", idx);
	}
	return 0;
}


