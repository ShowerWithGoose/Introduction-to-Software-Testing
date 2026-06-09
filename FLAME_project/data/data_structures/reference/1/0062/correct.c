#include<stdio.h>
void FOR(int x);
int check(int a[]); 
int n;
int che[1000],a[1000];
int main()
{	
	scanf("%d",&n);
	FOR(n);
	return 0;
}

void FOR(int x)
{	
	int i;
	if(x!=1)
	{
		for(a[x]=1;a[x]<=n;a[x]++)
		{
			FOR(x-1);
		}
	}
	else
	{
		for(a[1]=1;a[1]<=n;a[1]++)
		{
			if(check(a))
			{
				for(i=n;i>=1;i--)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
			}
		}
	}
}
int check(int a[])
{	
	int i;
	int sum=0;	
	for(i=1;i<=n;i++)
	{
		che[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		sum+=che[i];
	 } 
	 for(i=1;i<=n;i++)
	 	che[i]=0;
	 if(sum==n)
	 return 1;
	 else
	 return 0;

}




