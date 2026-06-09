#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int cmp(const void *, const void *);
typedef struct hyb {
	long long xn;
	long long an;
} block;
block a[200];
block b[200];
block c[40000];
char s0[10000];
char s1[10000];
char word[30];
int main() {
	int lena, lenb, lenc, flag;
	lena = lenb = lenc = flag = 0;
	gets(s0);
	int len = strlen(s0);
	for (int i = 0; i < len; i++) {
		if (i == 0 || ((isdigit(s0[i]) || s0[i] == '-') && ((s0[i - 1] != '-') && (0 == isdigit(s0[i - 1]))))) {
			for (int j = 0; isdigit(s0[i + j]) || s0[i + j] == '-'; j++) {
				word[j] = s0[i + j];
			}
			if (!flag) {
				a[lena].an = (long long)atoi(word);
				flag = 1;
			} else {
				a[lena++].xn = (long long)atoi(word);
				flag = 0;
			}
			memset(word, '\0', 30);
		}
	}
	gets(s1);
	flag = 0;
	len = strlen(s1);
	for (int i = 0; i < len; i++) {
		if (i == 0 || ((isdigit(s1[i]) || s1[i] == '-') && ((s1[i - 1] != '-') && (0 == isdigit(s1[i - 1]))))) {
			for (int j = 0; isdigit(s1[i + j]) || s1[i + j] == '-'; j++) {
				word[j] = s1[i + j];
			}
			if (!flag) {
				b[lenb].an = (long long)atoi(word);
				flag = 1;
			} else {
				b[lenb++].xn = (long long)atoi(word);
				flag = 0;
			}
			memset(word, '\0', 30);
		}
	}
	for (int i = 0; i < lena; i++) {
		for (int j = 0; j < lenb; j++) {
			c[lenc].an = a[i].an * b[j].an;
			c[lenc].xn = a[i].xn + b[j].xn;
			lenc++;
		}
	}
	for (int i = 0; i < lenc - 1; i++) {
		for (int j = i + 1; j < lenc; j++) {
			if (c[i].xn == c[j].xn) {
				c[i].an += c[j].an;
				for (int l = j; l < lenc - 1; l++) {
					c[l] = c[l + 1];
				}
				lenc--;
				j--;
			}
		}
	}
	qsort(c, lenc, sizeof(c[0]), cmp);
	for (int i = 0; i < lenc; i++) {
		if (c[i].an) {
			printf("%lld %lld ", c[i].an, c[i].xn); //TODO
		}
	}
	return 0;
}
int cmp(const void *x, const void *y) {
	long long *xx = (long long *)x;
	long long *yy = (long long *)y;
	return *xx < *yy;
}

