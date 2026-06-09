#include <stdio.h>
int a[11]={0,1,2,3,4,5,6,7,8,9,10};
int change(int i,int n)
{
	int t=i;
	int min=a[t],m=t;
	while(i<n)
	{
		for(t=i;t<n;t++)
		{
			if(a[t+1]<min)
			{
				min=a[t+1];
				m=t+1;
			}
		}
		a[m]=a[i];
		a[i]=min;
		i++;
		min=a[i];
		m=i;
	}
}
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	A:
	for(i=1;i<=n;i++)
	{
		if(i!=n)
		printf("%d ",a[i]);
		else
		printf("%d\n",a[i]);
	} 
	for(i=n;i>1;i--)
	{
		if(a[i]>a[i-1])
		{
			j=i-1;
			for(i=n;i>=1;i--)
			{
				if(a[i]>a[j])
				{
					k=a[i];
					a[i]=a[j];
					a[j]=k;
					change(j+1,n);
					goto A;
				}
			}
		}
	}
	return 0;
}

