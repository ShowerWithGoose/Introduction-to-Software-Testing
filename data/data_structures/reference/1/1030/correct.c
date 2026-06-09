#include<stdio.h>
int n;
int c[10]={0};
int a[10];
int check(int c)
{
    if(c==0)
    return 1;
    if(c==1) 
    return 0;
}
void dfs(int step)
{
        if(step==n){
			for(int i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
			return;
		}
        for(int i=0;i<n;i++){
			if(check(c[i])==1){
				c[i]=1;
				a[step]=i+1;
				dfs(step+1);
				c[i]=0;
			}
		}
}
int  main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}

