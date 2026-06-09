#include<stdio.h>
int main() {
	int n, k=0,i=0, j=0, a[4][101]={0}, point[101] = {0}, sum[101]={0}, max=0;
	scanf("%d", &n);
	for (i = 1;i <= n;i++) {
		scanf("%d%d%d%d", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);
	}
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (a[2][i] == a[0][j]&&a[3][i]==a[1][j]) {
				point[i] = j;
				break;
			}
		}
	}
	for (i = 1;i <= n;i++) {
		k = i;
		while (point[i] != 0) {
			sum[k]++;
			i = point[i];
		}
		i = k;
	}
	for (i = 1;i <= n;i++) {
		if (sum[i] > max) {
			max = sum[i];
			k = i;
		}
	}
	printf("%d %d %d",max+1,a[0][k],a[1][k]); 
	return 0;
}

