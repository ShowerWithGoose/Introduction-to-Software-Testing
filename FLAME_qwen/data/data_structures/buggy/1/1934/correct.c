#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int bool[20];
int list[20];
void prt(int n, int i) {
	if (n == i) {
		for (int j = 0; j < n; j++)printf("%d ",list[j]);
		printf("\n");
	}
	for (int j = 1; j <= n; j++) {
		if (bool[j])continue;
		else {
			bool[j] = 1;
			list[i] = j;
			prt(n, i + 1);
			bool[j] = 0;
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	prt(n, 0);
}


