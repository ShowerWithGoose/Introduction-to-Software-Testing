#include <stdio.h>
#include <string.h>
void swap(int *a,int *b)
{
	int v=*b;
	*b=*a;
	*a=v;
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j,r,temp=9,count;
	for(i=0;i<n;i++)
	a[i]=i+1;
	while(1)
	{
		temp=9;
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
		for(j=n-2;j<n&&j>=0;j--)
		{
			if(a[j]<a[j+1])
			{
				break;
			}
		}
		if(j<0) 
		break;
		for(i=j+1;i<n;i++)
		{
			if((a[i]<=temp)&&(a[i]>a[j]))
			{
				temp=a[i];
				count=i;
			}
		}
		swap(&a[j],&a[count]);
		for(i=j+1,r=n-1;i<r;i++,r--)
		swap(&a[i],&a[r]);
	}
	
	return 0;
}

