#include<stdio.h>

int a[12];

int jc(int n)
{
	int ans=1;int i;
	for(i=n;i>=2;i--)ans*=i;
	return ans;
}

void myprint(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
}

void px(int a[],int l,int r)
{
	int i,j;
	for(i=l;i<=r-1;i++)
	{
		for(j=l;j<=r+l-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j+1];
				a[j+1]=a[j];
				a[j]=tmp;
			}
		}
	}
}

int min(int a[],int l,int r,int p)
{
	int min=l;
	int i;
	for(i=l+1;i<=r;i++)
	{
		if(a[min]>a[i]&&a[i]>p)min=i;
	}
	return min;
}

int main()
{	
	int n;scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	int i;
	for(i=1;i<=n;i++)a[i]=i;
	myprint(a,n);
	int num=0;int goal=jc(n);
	flag:
	for(i=n-1;i>=1;i--)
	{
		if(a[i]<a[i+1])
		{
			int min0=min(a,i+1,n,a[i]);
			int tmp=a[min0];
			a[min0]=a[i];
			a[i]=tmp;
			px(a,i+1,n);
			break;
		}
	}
	myprint(a,n);
	num++;
	if(num==goal-1)return 0;
	else goto flag;
}



