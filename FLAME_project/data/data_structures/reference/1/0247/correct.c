#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	int a[100],b,i,sum=1,p,m,min,n,mid;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		a[i]=i;
		sum=sum*i;
	}
	for(i=1;i<=N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	min=a[N];
	n=N;
	for(sum;sum>1;sum--)
	{
		for(i=N-1;i>=1;i--)
		{
			if(a[i]<a[i+1])
			{
				p=a[i];
				m=i;
				break;
			}
		}
		if(m==N-1)
		{
			min=a[N];
			n=N;
		}
		else
		for(i=N-1;i>m;i--)
		{
			if(min<=p)
			{
				min=a[i];
				n=i;
			}
			if(a[i]<min&&a[i]>p)
			{
				min=a[i];
				n=i;
			}
		}
		a[m]=min;
		a[n]=p;
		for(i=m+1;i<=(N+m+1)/2;i++)
		{
			mid=a[i];
			a[i]=a[N+m+1-i];
			a[N+m+1-i]=mid;
		}
		min=a[N];
	    n=N;
		for(i=1;i<=N;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	}
	return 0;
}

