#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int a[100], i = 0;
	int p, ch;
	while (scanf("%d", &p) != EOF) {
		if (p == -1)
			break;
		else if (p == 1) {
			if (i == 100) {
				printf("error ");
			} else {
				scanf("%d", &ch);
				a[i] = ch;
				i++;
			}
		} else {
			i--;
			if (i < 0)
				printf("error ");
			else {
				printf("%d ", a[i]);
			}
		}
	}
	return 0;
}
