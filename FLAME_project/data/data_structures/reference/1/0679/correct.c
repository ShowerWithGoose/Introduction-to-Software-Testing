#include <stdio.h>
#include <string.h>
int a[15];

void rev(int  *s1, int *s2) {
	int hi = 0, low = 0;
	char temp;
	while (s1 + hi < s2)
		hi++;
	for (hi--; hi > low; low++, hi--) {
		temp = *(s1 + low);
		*(s1 + low) = *(s1 + hi);
		*(s1 + hi) = temp;
	}
}

int pl(int *first, int *last) {
	if (first + 1 == last)
		return 0;
	int *i = last - 1;
	for (;;) {
		int *j = i;
		--i;
		if (*i < *j) {
			int *j1 = last;
			while (!(*i < *--j1));

			int tem = *i;
			*i = *j1;
			*j1 = tem;
			rev(j, last);
			return 1;
		}

		if (i == first) {
			rev(first, last);
			return 0;
		}
	}
}

int dg(int m) {
	if (m > 1)
		return m * dg(m - 1);
	else
		return 1;
}

int main() {
	int i;
	scanf("%d", &i);
	for (int j = 0; j < i; j++) {
		a[j] = j + 1;
	}
	for (int t = 0; t < dg(i); t++) {
		for (int j = 0; j < i; j++) {

			printf("%d ", a[j]);
		}
		pl(a, a + i);
		printf("\n");
	}
	return 0;
}


