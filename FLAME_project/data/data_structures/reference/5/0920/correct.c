#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int co;
	int en;
} a[100050], b[100050], p[100050];
int cnta = 0, cntb = 0;
char c = ' '; 
int cmpfuc(const void *a, const void *b) {
	struct node *m = (struct node *)a;//强制类型转换 
	struct node *n = (struct node *)b;
	return n->en - m->en;//由大到小排序 
}
int main() {
	while (c != '\n') {
		scanf("%d%d%c", &a[cnta].co, &a[cnta].en, &c);
		cnta++;
	}
	c = ' ';//何以加此？
	while (c != '\n') {
		scanf("%d%d%c", &b[cntb].co, &b[cntb].en, &c);
		cntb++;
	}
	int k = 0;
	for (int i = 0; i < cnta; i++) {
		for (int j = 0; j < cntb; j++) {
			p[k].co = a[i].co * b[j].co;
			p[k].en = a[i].en + b[j].en;
			k++;
		}
	}
	qsort(p, k, sizeof(p[0]), cmpfuc);
	for (int i = 0; i < k; i++) {
		if (p[i].en == p[i + 1].en && p[i].en != 0) {
			p[i + 1].co += p[i].co;
			p[i].co = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (p[i].co != 0) printf("%d %d ", p[i].co, p[i].en);
	}
	return 0;
}

