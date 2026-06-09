#include <stdio.h>
int n;
int prints[11]={1,2,3,4,5,6,7,8,9,10};
int print();
int pailie();
int flag=0;
int main()
{
	int sum=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sum=sum*i;
	}
	print();
	for(int i=0;i<sum;i++)
	{
		pailie();
		if(flag==1)
		{
			break;
		}
		print();
	}
	return 0;
}
int print()
{
	int i;
	for(i=0;i<n-1;i++)
	{
		printf("%d ",prints[i]);
	}
	printf("%d\n",prints[i]);
}
int pailie()
{
	int j;
	for(j=n-2;j>=0;j--)
	{
		if(prints[j]<prints[j+1])
		{
			break;
		}
	}
	if(j<0)
	{
		flag=1;
	}
	int k=j,temp=j+1;
	for(int l=k+1;l<n;l++)
	{
		if(prints[l]>prints[k]&&prints[l]<prints[temp])
		{
			temp=l;
		}
	}
	int change=prints[k];
	prints[k]=prints[temp];
	prints[temp]=change;
	for(int l=k+1,s=n-1;l<s;l++,s--)
	{
		change=prints[l];
		prints[l]=prints[s];
		prints[s]=change;
	}
}


