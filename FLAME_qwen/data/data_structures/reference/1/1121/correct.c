#include<stdio.h>
#include<stdlib.h>
int fact(int n)
{
	if(n<=1)
	return 1;
	else
	return n*fact(n-1);
}
int main()
{
	int n,i,j,k,p,num[15],low,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	num[i]=i+1;
	for(i=0;i<n-1;i++)
	printf("%d ",num[i]);
	printf("%d\n",num[i]);
	for(i=1;i<fact(n);i++)
	{
		for(j=n-1;j>=1;j--)
		{
			if(num[j-1]<num[j])
			{
				k=j-1;
				low=j;
				break;
			}
		}
		for(p=n-1;p>k;p--)
		{
			if(num[k]<num[p]&&num[low]>num[p])
			low=p;
		}
		temp=num[k];
		num[k]=num[low];
		num[low]=temp;
		for(p=k+1,j=n-1;p<j;p++,j--)
		{
			temp=num[p];
			num[p]=num[j];
			num[j]=temp;
		}
		for(j=0;j<n-1;j++)
	    printf("%d ",num[j]);
	    printf("%d\n",num[j]);
	}
	return 0;
} 


