#include <stdio.h>
#include <string.h>
void f(int *num,int l,int w,int n)
{
	int i,j,p=0,k,temp;
	if(l==2)
	{
		for(i=0;i<n;i++)
			printf("%d ",num[i]);
		printf("\n");
		for(i=0;i<w;i++)
			printf("%d ",num[i]);
		printf("%d %d\n",num[w+1],num[w]);
	}
	else if(l==1)
	{
		printf("%d\n",num[0]);
	}
	else
	{
		for(i=w;i<n;i++)
		{
			f(num,l-1,w+1,n);
			if(num[w]<n)
			{
				for(j=w+1;j<n;j++)
				{
					for(k=j+1;k<n;k++)
					{
						if(num[j]>num[k])
						{
							temp=num[j];
							num[j]=num[k];
							num[k]=temp;
						}
					}
				}
				for(j=w+1;j<n;j++)
				{
					if(num[w]<num[j])
					{
						temp=num[w];
						num[w]=num[j];
						num[j]=temp;
						break;	
					}	
				}
			}
		}
	}
}
int main()
{
	int a[15]={0},n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	f(a,n,0,n);
	return 0;
 } 

