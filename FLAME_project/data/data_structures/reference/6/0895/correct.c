#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i = 0, a, b[100];
int main() {

	while (scanf("%d", &a) != EOF) {
		if (a == 1 && i == 99) {
			printf("error ");
		}
		if (a == 1 && i != 99) {
		
			scanf("%d", &b[i]);	i++;
		}
		if (a == 0 && i == 0) {

			printf("error ");
		}
		if (a == 0 && i != 0) {
			
			printf("%d ", b[i-1]);i--;
		}

	}
	return 0;
}

