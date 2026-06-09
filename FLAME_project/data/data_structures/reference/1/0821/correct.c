#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define M 100007
int a[M],book[M],n;
void dfs(int step) {
	int i;
	if(step==n+1) {
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);			
		}
		puts("");
		return;
	}
	for(i=1; i<=n; i++) {
		if(book[i]==0) {
			book[i]=1;
			a[step]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
} 
int main() {
	scanf("%d",&n);
	dfs(1);
	return 0;
}





