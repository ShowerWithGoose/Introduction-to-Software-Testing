#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	int stack[105], sign, n, i = 0;
	while (1) {
		scanf("%d", &sign);
		if (sign == 1) {
			scanf("%d", &n);
			if (i == 100)
				printf("error ");
			else
				stack[i++] = n;
		}
		if (sign == 0)
		{
			if (i == 0)
				printf("error ");
			else
				printf("%d ", stack[--i]);
		}
		if (sign == -1)
			break;
	}
}


