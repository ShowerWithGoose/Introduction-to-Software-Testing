#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int flag[100];
char str[5000];
char out[100];
int len;
void range(int step);

int main () {
	int n;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		str[i] = i + 1 + '0';
	}
	str[i] = '\0';
	len = strlen(str);
	range(0);


	return 0;
}

void range(int step) {
	if (step == len) {
		out[step] = '\0';
		for (int i = 0; i < strlen(out); i++) {
			printf("%c ", out[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < len; i++) {
		if (flag[i] == 0) {
			flag[i] = 1;
			out[step] = str[i];
			range(step + 1);
			flag[i] = 0;
		}
	}
}

