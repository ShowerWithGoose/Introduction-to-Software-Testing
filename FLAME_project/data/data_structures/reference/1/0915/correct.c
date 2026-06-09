#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<=b)?a:b)
#define max(a,b) ((a>=b)?a:b)
int n;
int a[11];
int vis[11];
void print() {
	for(int i=1; i<=n; i++) {
		printf("%d ",a[i]);
	}
	return;
}
void dfs(int x) {
	if(x==n) {
		print();
		printf("\n");
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			a[x+1]=i;
			vis[i]=1;
			dfs(x+1);
			a[x+1]=0;
			vis[i]=0;
		}
	}
}
int main() {
	scanf("%d",&n);
	dfs(0);
	return 0;
}




