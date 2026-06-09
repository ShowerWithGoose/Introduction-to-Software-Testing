#include <stdio.h>
#include <string.h>
int n;
int isused[50];
void dfs(int x,int num)
{
	int i,y=1,m;
	if(x==n+1)
	{
		for(m=num;m/10!=0;y*=10){
			m/=10;
		}
		for(;y!=0;y/=10)
		{
			printf("%d ",num/y);
			num=num-num/y*y;
		}
		putchar(10);
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(isused[i]==0)
		{
			isused[i]=1;
			dfs(x+1,num*10+i);
			isused[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1,0);
	return 0;
}

