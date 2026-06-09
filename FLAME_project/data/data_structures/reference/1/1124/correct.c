#include<stdio.h>
int a[11]={0};
int main()
{
	int n,m,i,j,k,sum=1,min,minn,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		sum*=i;
	}
	for(m=0;m<sum;m++)
	{
		for(i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");
		min=20;
		for(j=n;j>1;j--)
		{
			if(a[j-1]<a[j])
			break;
		}
		for(k=j;k<=n;k++)
		{
			if(a[k]>a[j-1]&&a[k]<min)
			{
				minn=k;
				min=a[k];
			}
		}
		t=a[j-1];
	    a[j-1]=a[minn];
	    a[minn]=t;
		for(i=j,k=n;i<k;i++,k--)
		{
			t=a[i];
	        a[i]=a[k];
	        a[k]=t;
		}
		
	}
}



