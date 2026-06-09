#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int n;
int a[100];

void dfs(int x,int num) {
	int i;
	if(x==n+1) {
		int l=pow(10,n-1);
		for(i=1;i<=n;i++){
			printf("%d ",num/l);
			num%=l;
			l/=10;
		}
		printf("\n");
		return;
	}
	for(i=1; i<=n; i++) {
		if(a[i]==0) {
			a[i]=1;
			dfs(x+1,num*10+i);
			a[i]=0;
		}
	}
}

int main() {
	scanf("%d",&n);
	dfs(1,0);
	return 0;
}



