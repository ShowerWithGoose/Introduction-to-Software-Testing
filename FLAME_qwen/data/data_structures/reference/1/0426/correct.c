#include<stdio.h>
int homo[11],xue[11];
void linqin(int x,int n)
{
	if (x == n + 1) {
		for (int i = 1; i <= n; i++)
			printf("%d ", xue[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (homo[i])continue;
		homo[i] = 1;
		xue[x] = i;
		linqin(x + 1, n);
		homo[i] = 0;
		xue[x] = 0;
	}
	return;
}
int main()
{
	int n;
	scanf("%d", &n);
	linqin(1, n);
	return 0;
}



