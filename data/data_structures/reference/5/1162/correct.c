#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define int long long
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
int n, m, q, i, j, lst[1111], nxt[1111], cnt1, cnt2, cnt3;
int x[1111], y[1111], a[1111], b[1111], c[1111], d[1111];
char c1, c2, c3;
void swap(int *a, int *b) {
	int tmp = *a; *a = *b; *b = tmp;
}
void sort() {
	for(i = 1; i <= cnt3; i++)
		for(j = 1; j < cnt3; j++) {
			if(x[j] < x[j + 1]) {
				swap(&x[j], &x[j + 1]);
				swap(&y[j], &y[j + 1]);
			} 
		}
}
signed main() {
	while(1) {
		cnt1++;
		scanf("%d%c%d%c", &b[cnt1], &c1, &a[cnt1], &c2);
		if(c2 == '\n') break;
	}
	while(1) {
		cnt2++;
		scanf("%d%c%d%c", &d[cnt2], &c1, &c[cnt2], &c2);
		if(c2 == '\n') break;
	}
	for(i = 1; i <= cnt1; i++) {
		for(j = 1; j <= cnt2; j++) {
			x[++cnt3] = a[i] + c[j];
			y[cnt3] = b[i] * d[j];
		}
	}
	sort(); x[cnt3 + 1] = -1;
	for(i = 1; i <= cnt3;) {
		int ans = 0;
		while(x[i + 1] == x[i]) {
			ans += y[i]; i++;
		}
		ans += y[i];
		printf("%lld %lld ", ans, x[i]); i++;
	}
	printf("\n");
	return 0;
}

