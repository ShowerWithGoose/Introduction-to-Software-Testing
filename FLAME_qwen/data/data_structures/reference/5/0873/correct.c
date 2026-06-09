#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct polynomial {
	int xs;
	int zs;
}a[100], b[100], c[10000];
int cmp1(const void* a, const void* b) {
	return (*(struct polynomial*)a).zs < (*(struct polynomial*)b).zs ? 1 : -1;
}
int cmp2(const void* a, const void* b) {
	return (*(struct polynomial*)a).zs > (*(struct polynomial*)b).zs ? 1 : -1;
}
int main() {
	int i, j;
	char x;
	int na = 0;
	int nb = 0;
	int k = 0;
	do {
		scanf("%d%d%c", &a[na].xs, &a[na].zs, &x);
		na++;
	} while (x != '\n');
	do{
		scanf("%d%d%c", &b[nb].xs, &b[nb].zs, &x);
		nb++;
	} while (x != '\n');
	//printf("%d %d ", na, nb);
	qsort(a, na, sizeof(a[0]), cmp1);
	qsort(b, nb, sizeof(b[0]), cmp1);
	/*for (int i = 0; i < na; i++) {
		printf("%d %d ", a[i].xs, a[i].zs);
	}
	printf("\n");
	for (int i = 0; i < nb; i++) {
		printf("%d %d ", b[i].xs, b[i].zs);
	}printf("\n");*/
	for (i = 0; i < na; i++) {
		for (j = 0; j < nb; j++) {
			c[k].xs = a[i].xs * b[j].xs;
			c[k].zs = a[i].zs + b[j].zs;
			k++;
		}
	}
	
	qsort(c, k, sizeof(c[0]), cmp2);
//for (int i = 0; i < k; i++) {
	//	printf("%d %d ", c[i].xs, c[i].zs);
	//}
//printf("\n");
	for (int m = 0; m < k; m++) {
		if (c[m + 1].zs == c[m].zs) {
			c[m + 1].xs += c[m].xs;
			c[m].xs = 0;
		}
		
	}
	qsort(c, k, sizeof(c[0]), cmp1);
	for (int m = 0; m < k; m++) {
		if (c[m].xs != 0)
			printf("%d %d ", c[m].xs, c[m].zs);
		else
			continue;
	}
	return 0;
}

