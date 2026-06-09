#include <stdio.h>
#include <string.h>
void dfs(int );
int n;
int queue_number[10];
int tag[9];
int main()
{
	scanf("%d",&n); 
	dfs(n);
	return 0;
}
void dfs(int t)
{
	int i;
	if(t==0){
		for(i=0;i<n;i++){
			printf("%d",queue_number[i]);
			if(i!=n-1)printf(" ");
			else printf("\n");
		}
		return;
	}
	for(i=1;i<=n;i++){
		if(tag[i]==0){
			queue_number[n-t]=i;
			tag[i]=1;
			dfs(t-1);
			tag[i]=0;
		}
	}
}



