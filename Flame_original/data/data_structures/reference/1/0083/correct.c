#include<stdio.h>
#include<math.h>
#include<string.h>
int n;
int g[10000],u[10000];
void dfs(int m);
void pr();
int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}
void dfs(int m)
{
    int i;
	if(m==n){
		pr();
        return;
    }
	for(i=0;i<n;i++){
	if(!u[i]){
		u[i]=1;
		g[m]=i+1;
		dfs(m+1);
		u[i]=0;
	}
	
    }
}
void pr()
{
	int i;
	for(i=0;i<n;i++){
		printf("%d ",g[i]);
	}
	printf("\n");
}

