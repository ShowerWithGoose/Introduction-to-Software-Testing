#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 
#include<stdlib.h>

long long Pow(int x,int y)
{
	long long sum=1;
	int i;
	for(i=1;i<=y;i++)
	{
		sum*=x;
	}
	return sum;
}

int main()
{
	int n,j,b[15],num,c[15]={0},d,flag=0,k;
	long long min=0,max=0,a,l;
	scanf("%d",&n);
	if(n<=9)
	{
		for(j=1;j<=n;j++)
		{
			min+=j*Pow(10,n-j);
		}
		for(j=n;j>=1;j--)
		{
			max+=j*Pow(10,j-1);
		}
	}
	for(a=min;a<=max;a=a+9)
	{
		for(j=1;j<=n;j++)
		{
			c[j]=0;
		}
		flag=0;
		num=n;
		l=a;
		while(l>0)
		{
			d=l-l/10*10;
			b[num]=d;
			c[d]=-1;
			l/=10;
			num--;
		}
		for(k=1;k<=n;k++)
		{
			
			if(c[k]==0)
			{
				flag=-1;
			}
		}
		if(flag==0)
		{
			for(k=1;k<=n;k++)
			{
				printf("%d ",b[k]);
			}
			printf("\n");
		}
	}
	
	
	
	return 0;
}

