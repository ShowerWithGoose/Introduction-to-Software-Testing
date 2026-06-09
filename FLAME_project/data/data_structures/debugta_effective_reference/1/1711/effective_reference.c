#include<stdio.h>
#include<string.h>
int a[11];
int flag[11];
int a[11];
void f(int,int);
void put(int);
int temp;

int main()
{
	int n,m;
	scanf("%d",&n);
	int i,r;
	for(i=1;i<=n;i++)
	{
		a[i]=i;
	}	
	for(i=1;i<=n;i++)
	{
		m=1;
		a[m++]=i;
		flag[i]=1;
		f(m,n);
		for(r=1;r<=n;r++)
		flag[r]=0;
	}
	if(n==1)
	printf("1");
	return 0;
}
void f(int t,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(flag[i]==1)
			continue;
		else if(flag[i]!=1)
		{
			flag[i]=1;
			a[t]=a[i];
			
			if(t==n)
			{
				put(n);
//				temp=1;
			}
			else
			{
				f(t+1,n);
				int q=a[t];
				int p=a[t+1];
				flag[q]=0;
				flag[p]=0;
			}
		}
	}
	
}
void put(int n)
{
	int k;
	for(k=1;k<n;k++)
		printf("%d ",a[k]);
	printf("%d",a[k]);
	printf("\n");
}



