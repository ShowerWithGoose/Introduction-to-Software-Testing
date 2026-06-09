#include <stdio.h>
int a[1000000];
int f[1000000];
int h[1000000];
int num;
int s[100000];
int cnt;
int i, hi;

void search(int i) {
	if (!f[i])
		return ;
	search(2 * i + 1);
	if (!f[2 * i + 1] && !f[2 * i + 2])
//		s[cnt++] = i;
		printf("%d %d\n", a[i], h[i]);
	search(2 * i + 2);
}

int main(void) {
	scanf("%d", &num);
	int x;
	while (num--) {
		i = 0, hi = 1;
		scanf("%d", &x);
		if (!f[0]) {
			a[0] = x;
			f[0] = 1;
			h[0] = 1;
		} else {
			while (f[i]) {
				hi++;
				if (a[i] > x) {
					i = i * 2 + 1;
				} else {
					i = i * 2 + 2;
				}
			}
			a[i] = x;
			f[i] = 1;
			h[i] = hi;
		}
	}
	i = 0;
	search(0);
	return 0;
}

