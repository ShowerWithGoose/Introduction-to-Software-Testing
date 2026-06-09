#include<stdio.h>
#include<string.h>
void nat(int str1[],int str2[],int m,int tim,int lef)
{
	int i,l,k;
	if(lef>=1)
	{
		for(i=0;i<m;i++)
		{
			if(str1[i]>0&&str1[i]<=10)
			{
				str2[tim]=str1[i];
				k=str1[i];
				str1[i]=0;
				nat(str1,str2,m,tim+1,lef-1);
			}
			str1[i]=k;
			k=0;
		}
	}
	else
	{
		for(i=0;i<m;i++)
		{
			if(str2[i]<str2[i+1])
			{
				l=1;
				break;
			}
			else
		l=0;
		}
		for(i=0;i<(2*m-1);i++)
		{
			if(i%2==0) 
			printf("%d",str2[i/2]);
			else
			printf(" ");
		}
		if(l==1)
		printf("\n");
	}
}
int main()
{
	int i,n,t,nu;
	int b[11],c[11],d[11];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		b[i]=i+1;
		c[i]=0;
	}
	b[i]=0;
	c[i]=0;
	t=0;
	nu=n;
	nat(b,c,n,t,nu);
	return 0;
}

