#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
int n;
int book[1001],a[1001];
void dfs(int step) {
	int i;
	if(step==n+1) {
		for(i=1; i<=n; i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(book[i]==0){
			a[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
}
int main() {
	scanf("%d",&n);
	dfs(1);
	getchar();
	getchar();
	return 0;
}


