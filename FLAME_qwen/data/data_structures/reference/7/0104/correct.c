#include<stdio.h>

int n,ls[1000005],rs[1000005],cnt=0,dep[1000005],v[100005];
int a[100005],b[100005],s0=0;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if(cnt==0) v[++cnt]=x;else
		{
			int yu=1;
			while(1)
			{
				if(v[yu]<=x) 
				{
					if(!rs[yu]) 
					{
						rs[yu]=++cnt;v[cnt]=x;
						break;
					}
					yu=rs[yu];
				}else
				{
					if(!ls[yu]) 
					{
						ls[yu]=++cnt;v[cnt]=x;
						break;
					}
					yu=ls[yu];
				}
			}
		}
	}
	dep[1]=1;
	for(int i=1;i<=cnt;i++) 
		dep[ls[i]]=dep[i]+1,dep[rs[i]]=dep[i]+1;
	for(int i=1;i<=cnt;i++)
		if((!rs[i])&&(!ls[i])) a[++s0]=v[i],b[s0]=dep[i];
	for(int i=1;i<=s0;i++)
		for(int j=i+1;j<=s0;j++)
			if(a[i]>a[j]) 
			{
				int t=a[i];a[i]=a[j];a[j]=t;
				t=b[i];b[i]=b[j];b[j]=t;
			}
	for(int i=1;i<=s0;i++)
		printf("%d %d\n",a[i],b[i]);
	return 0;
}

