#include<stdio.h>

void Go(int *arr,int k,int n)
{
	if(k==n-1)
	{
		for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	else 
	{
		for(int i=k;i<n;i++)
		{
			int temp=arr[i];
			for(int j=i;k<j;j--)
				arr[j]=arr[j-1];
			arr[k]=temp;
			Go(arr,k+1,n);
			temp=arr[k];
			for(int j=k;j<i;j++)
				arr[j]=arr[j+1];
			arr[i]=temp;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	Go(arr,0,n);
	return 0;
 } 

