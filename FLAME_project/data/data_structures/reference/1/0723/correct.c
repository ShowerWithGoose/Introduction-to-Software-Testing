#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n;
int vis[12];
int ans[12];
void make(int now)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) 
		{
			vis[i]=1;
		    ans[now]=i;	
			make(now+1);
			vis[i]=0;
		}
	}
	if(now==n)
	{
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}
int main()
{
	//freopen("ans.txt","w",stdout);
    scanf("%d",&n);
    make(1) ;
	return 0;
}





