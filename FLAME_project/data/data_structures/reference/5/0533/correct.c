//solution 1 :dynamic array+struct 动态结构数组 qsor排序
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coe;
	int pow;
} num;

typedef struct {
	num *array;
	int used;
	int size;
} Array;

void initArray(Array *, int);

void insertArray(Array *, num);
Array a, b, ans;

int cmp(const void *a, const void *b) {
	num *aa = (num *)a;
	num *bb = (num *)b;
	if (aa->pow == bb->pow ) {
		aa->coe += bb->coe;
		bb->coe = 0;
		return -1;
	} else {
		return aa->pow > bb->pow ? -1 : 1;
	}
}

int main(void) {

	initArray(&a, 1);
	initArray(&b, 1);
	initArray(&ans, 1);

	char c;
	while (1) {
		num n;
		scanf("%d %d", &n.coe, &n.pow);
		c = getchar();
		insertArray(&a, n);
		if (c == '\n' || c == '\r') {
			break;
		}
	}
	while (1) {
		num n;
		scanf("%d %d", &n.coe, &n.pow);
		c = getchar();
		insertArray(&b, n);
		if (c == '\n' || c == '\r') {
			break;
		}
	}

//	int t = 0;
	for (int i = 0; i < a.used; i++) {
		for (int j = 0; j < b.used; j++) {
			num n;
			n.coe = a.array[i].coe * b.array[j].coe;
			n.pow = a.array[i].pow + b.array[j].pow;
			insertArray(&ans, n);
//			printf("加入了%dx^%d\n", ans.array[t++].coe, ans.array[t].pow);
		}
	}

	qsort(ans.array, ans.size, sizeof(num), cmp);

//	printf("-------\n");
	for (int k = 0; k < ans.used; k++) {
		if (ans.array[k].coe != 0)
			printf("%d %d ", ans.array[k].coe, ans.array[k].pow);
	}

	return 0;
}

void initArray(Array *a, int initialSize) {
	a->array = malloc(initialSize * 8);
	a->size = initialSize;
	a->used = 0;
}

void insertArray(Array *a, num n) {
	if (a->size == a->used) {
		a->size = a->size * 2;
		a->array = realloc(a->array, a->size * sizeof(num));
		for (int i = 1; i <= a->size / 2; i++) {
			a->array[a->size / 2 + i].coe = 0;
			a->array[a->size / 2 + i].pow = 0;
		}
	}
	a->array[a->used++] = n;
}





