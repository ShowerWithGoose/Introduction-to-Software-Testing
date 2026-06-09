#include <stdio.h>
#include <string.h>

#define MAX 10 + 1

int flag[MAX];
int ans[MAX];

void solve(int num, int a[], int len);

int main(void) {

	int a = 0;
	scanf("%d", &a);
	int get[MAX];
	int i;
	for (i = 0; i < a; i++)
		get[i] = 1 + i;
	solve(0, get, a);

	return 0;
}

void solve(int num, int a[], int len) {
	if (num == len) {
		for (int i = 0; i < len; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	for (int i = 0; i < len; i++) {
		if (flag[i] == 0) {
			flag[i] = 1;
			ans[num] = a[i];
			solve(num + 1, a, len);
			flag[i] = 0;
		}
	}
}

