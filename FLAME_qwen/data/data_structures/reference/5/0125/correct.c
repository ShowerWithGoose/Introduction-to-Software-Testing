#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct expression {
	int coef;
	int pow;
} shi;
shi num1[2000], num2[2000], numans[2000];
int cmp(const void *p1, const void *p2);

int main() {
	int i, j, k = 0;
	int n1 = 0, n2 = 0;
	char ch;
	do {
		scanf("%d%d%c", &num1[n1].coef, &num1[n1].pow, &ch);
		n1++;
	} while (ch != '\n');
	do {
		scanf("%d%d%c", &num2[n2].coef, &num2[n2].pow, &ch);
		n2++;
	} while (ch != '\n');
	qsort(num1, n1, sizeof(shi), cmp);
	qsort(num2, n2, sizeof(shi), cmp);
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			numans[k].coef = num1[i].coef * num2[j].coef;
			numans[k].pow = num1[i].pow + num2[j].pow;
			k++;
		}
	}
	qsort(numans, k, sizeof(shi), cmp);
	for (i = 0; i < k; i++) {
		if (numans[i].pow == numans[i + 1].pow && numans[i].pow != 0) {
			numans[i + 1].coef += numans[i].coef;
			numans[i].coef = 0;
		}
	}
	qsort(numans, k, sizeof(shi), cmp);
	for (i = 0; i < k; i++) {
		if (numans[i].coef == 0) {
			continue;
		} else {
			printf("%d %d ", numans[i].coef, numans[i].pow);
		}
	}
	return 0;
}

int cmp(const void *p1, const void *p2) {
	shi *a = (shi *)p1;
	shi *b = (shi *)p2;
	return b->pow - a->pow;
}

