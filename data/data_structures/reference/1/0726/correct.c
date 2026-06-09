#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n;
int a[10];
int f(int len,int j);
void dfs(int len);
int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}
void dfs(int len){
	if(len==n){
		for(int i=0;i<n;i++) printf("%d ",a[i]);
		printf("\n");
		//return;//?
	}
	for(int i=1;i<=n;i++){
		if(f(len,i)==1){//?
			a[len]=i;
			dfs(len+1);
		}
	}
}
int f(int len,int j){
	for(int i=0;i<len;i++){
		if(a[i]==j){
			return 0;
		}
	}
	return 1;
}



