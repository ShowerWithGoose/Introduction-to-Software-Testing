//输出全排列数
#include<stdio.h>
#define YES 1
#define NO 0
int order[10]={},is_mark[10]={0},n;
void recursion(int k) {
	int i;
	if(k>n) {
		for(i=1; i<n; i++) {
			printf("%d ",order[i]);
		}
		printf("%d\n",order[n]);
		return;

	} else {
		for(i=1; i<=n; i++) {
			if(!is_mark[i]) {
				order[k]=i;
				is_mark[i]=YES;
				recursion(k+1);
				order[k]=0;
				is_mark[i]=NO;
			}
		}

	}
}
int main() {
	scanf("%d",&n);
	recursion(1);
	return 0;
}

