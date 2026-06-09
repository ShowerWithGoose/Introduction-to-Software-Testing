#include<stdio.h>
#include<string.h>
int hx[1000],w[1000];
int n,sum,d=0;
int j,k;
void f(int p,int wd);
int main()
{
	int i;
	scanf("%d",&n);
	for(sum=1,i=n;i>=1;i--)
	{
		sum=sum*i;
	}
	
	f(1,d);
	return 0;
}

void f(int p,int wd)
{
	int i;
	if(wd>=sum)return ;
	if(p>n)
	{
		p-=1;
		for(i=1;i<=n;i++)
		{
			printf("%d ",w[i]);
		}
		printf("\r\n");
		wd+=1;
	}
	for(i=1;i<=n;i++)
	{
		if(hx[i]==0)
		{
			w[p]=i;
			hx[i]=1;
			f(p+1,wd);
			hx[i]=0;
			w[p]=0;
		}
	}
}

