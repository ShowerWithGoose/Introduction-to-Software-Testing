#include<stdio.h>
#include<string.h>
int a[11];
int flag[11];
int number[11];
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
		number[m++]=i;
		flag[i]=1;
		f(m,n);
		for(r=1;r<=n;r++)
		flag[r]=0;
	}
	if(n==1)
	printf("1");
	return 0;
}
void f(int j,int n)
{
	int t;
	for(t=1;t<=n;t++)
	{
		if(flag[t]==1)
			continue;
		else if(flag[t]!=1)
		{
			flag[t]=1;
			number[j]=a[t];
			
			if(j==n)
			{
				put(n);
//				temp=1;
			}
			else
			{
				f(j+1,n);
				int q=number[j];
				int p=number[j+1];
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
		printf("%d ",number[k]);
	printf("%d",number[k]);
	printf("\n");
}



