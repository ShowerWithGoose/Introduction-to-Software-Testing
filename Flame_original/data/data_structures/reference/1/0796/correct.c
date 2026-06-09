#include <stdio.h>
#include <stdlib.h>
void re(int aa[],int a,int b) {
	int i;
	int tmp=aa[b];
	for (i=b; i > a; i--)
		aa[i] = aa[i - 1];
	aa[a] =tmp;
}

void der(int aa[], int a, int b) {
	int i;
	int tmp = aa[a];
	for (i=a;i<b;i++)
		aa[i] = aa[i + 1];
	aa[b] = tmp;
}

void pailie(int a[],int d,int N) {
	int i=0;
	if (d > N) {
		for (;i<=N;i++)
			printf("%d ",a[i]);
		printf("\n");
	} else
		for (i=d;i<=N;i++) {
			re(a,d,i);
			pailie(a,d+1,N);
			der(a,d,i);
		}
}

int main() {
	int n,i=0;
	scanf("%d", &n);
	int aa[11];
	for (;i<n;i++)
		aa[i] = i+1;
	pailie(aa,0,n-1);
	return 0;
}

