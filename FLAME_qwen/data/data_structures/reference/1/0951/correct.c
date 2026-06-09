//1-5 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
void re(int *p,int l)
{
	if(l==1)
		return;
	int i,t;
	for(i=0;i<l/2;i++)
	{
		t=p[i];
		p[i]=p[l-1-i];
		p[l-1-i]=t;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k,flag,temp,min;
	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
	while(1)
	{
		flag=0;
		for(i=n-1;i>=1;i--)
		{
			if(a[i-1]<a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			break;
		min=10;
		k=0;
		for(j=i;j<n;j++)
		{
			if(a[j]<=min && a[j]>a[i-1])
			{
				min=a[j];
				k=j;
			}
		}
		temp=a[i-1];
		a[i-1]=a[k];
		a[k]=temp;
		re(&a[i],n-i);
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
	return 0;
}


