#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
int seat[15];
int mark[15];
void dfs(int id,int n)
{
	if(id>n){
		for(int i=1;i<=n;i++){
			printf("%d ",seat[i]);
		}
		printf("\n");
		return;
	}
	for(int cardId=1;cardId<=n;cardId++){
		if(mark[cardId]==0){
			seat[id]=cardId;
			mark[cardId]=1;
			dfs(id+1,n);
			mark[cardId]=0;
		}
	}
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(1,n);
	return 0;
}

