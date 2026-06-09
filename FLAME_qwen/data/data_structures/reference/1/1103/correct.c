#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int n;
int ans[15];
int visit[15];
void DFS(int x){
	int i;
	if(x>n){
		for(i=1;i<=n;i++)
			printf("%d ",ans[i]);
			printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	if(!visit[i]){
		ans[x]=i;
		visit[i]=1;
		DFS(x+1);
		visit[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	DFS(1);
}


