#include<stdio.h>
#include<math.h>

int main()
{
    int n,min,max,flag;
    int a[12];
    int temp;
	scanf("%d",&n);
	min=n;
	max=0;
	for(int i=n;i>0;i--)
	{
		min+=(n-i)*pow(10,i);
	}
	for(int i=0;i<n;i++)
	{
		max+=(i+1)*pow(10,i);
	}
	for(int i=min;i<max+1;i++)
	{
		temp=i;
		for(int j=n-1;j>=0;j--)
		{
			a[j]=temp%10;
			temp/=10;
		}
		for(int j=0;j<n-1;j++)
		{
			for(int vis=j+1;vis<n;vis++)
			{
				if(a[j]==a[vis]||a[vis]>n||a[j]>n||a[vis]==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(flag==1) break;
			printf("%d ",a[j]);
		}
		if(flag==0)
		{
			i+=8;
			printf("\n");
		}
		flag=0;
	}
	return 0;
}

