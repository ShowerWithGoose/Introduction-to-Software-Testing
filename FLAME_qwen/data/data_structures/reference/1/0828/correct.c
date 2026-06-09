#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<stdlib.h> 
#include<malloc.h>
#define N 100+9

int hash[10000+9],n,a[10000+9],k;
void f(int num)
{
	int i,j;
	if(num==1)
	{
		for(i=1;i<=n;i++)
		{
			if(!hash[i])
			{
				a[k++]=i;
				for(j=0;j<k;j++)
				{
					printf("%d ",a[j]);
				}
				printf("\n");
				k--;
				return ;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!hash[i])
		{
			a[k++]=i;
			hash[i]=1;
			f(num-1);
			hash[i]=0;
			k--;
		}
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	f(n);
}

