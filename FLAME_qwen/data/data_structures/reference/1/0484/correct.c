#include<stdio.h>
#include<string.h>
int a[15];
int n;
void func(int cur,int vis[])//cur指当前递归到的第几位数字 
{
	int i,j;
	int s[15]={0};
	int flag=1;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			a[cur]=i;
			for(j=1;j<=n;j++)
			{
				s[j]=vis[j];
			}
			s[i]=1;
		}
		else
		  continue;
		if(cur<n)
		{
			func(cur+1,s);
		}
	}
	for(j=1;j<=n;j++)
	{
		if(s[j]==0)
		{
			flag=0;
		}
	}
	if(flag)
	{
	   for(j=1;j<=n;j++)
	   {
		  printf("%d ",a[j]);
	   }
	   printf("\n");	
	}

}
int main()
{
	int vis[15]={0};
	scanf("%d",&n);
	func(1,vis);
	return 0;
}

