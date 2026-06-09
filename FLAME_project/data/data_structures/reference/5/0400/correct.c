#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct axn {
	int a;
	int n;
};

int cmp(const void* a, const void* b) {
	struct axn* c = (struct axn*)a;
	struct axn* d = (struct axn*)b;
	return d->n - c->n;
}

int main() {
	struct axn axn1[10086], axn2[10086], axn3[2 * 10086];
	int len1 = 0, len2 = 0;
	char space = ' ';
	for (; space != '\n'; len1++)
		scanf("%d%d%c", &axn1[len1].a, &axn1[len1].n, &space);
	space = ' ';
	for (; space != '\n'; len2++)
		scanf("%d%d%c", &axn2[len2].a, &axn2[len2].n, &space);
	int len3 = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			axn3[len3].a = axn1[i].a * axn2[j].a;
			axn3[len3].n = axn1[i].n + axn2[j].n;
			len3++;
		}
	}
	qsort(axn3, len3, sizeof(axn3[0]), cmp);
	for (int i = 0; i < len3 - 1; i++) {
		for (int j = i + 1; j < len3; j++) {
			if (axn3[i].n == axn3[j].n && axn3[i].n != 0) {
				axn3[i].a += axn3[j].a;
				axn3[j].a = 0;
			}
		}
	}
	for (int i = 0; i < len3; i++) {
		if (axn3[i].a != 0) {
			printf("%d %d ", axn3[i].a, axn3[i].n);
		}
	}
}
