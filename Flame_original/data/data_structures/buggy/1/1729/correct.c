#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int n;
void func(int *a,int o)
{
	if(o==1)
	{
		for(int k=0;k<n;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
		return;
	}
	else
	{
		for(int l=n-o;l<n;l++)
		{
			
	int r,s;
	for(r=0;r<n;r++)
	{
		for(s=n-o;s<n-1;s++)
		{
			if(a[s]>a[s+1])
			{
			int mid;
			mid=a[s];
			a[s]=a[s+1];
			a[s+1]=mid;
		}
		}
	}
			int mid;
			mid=a[l];
			a[l]=a[n-o];
			a[n-o]=mid;
			func(a,o-1);
			mid=a[l];
			a[l]=a[n-o];
			a[n-o]=mid;
		}
	}
}
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
    scanf("%d",&n);
    func(a,n);
	return 0;
}



