#include<stdio.h>
int n;
int a[100];

void digui(int x,int num)
{
	int i,j;
	int s[100]; 
	if(x==n+1)
	{
		//printf("%d\n",num);
		for(i=0;num>0;i++)
		{
		  s[i]=num%10;
		  num/=10;	
		}
		for(j=i-1;j>=0;j--)
		{
			if(j==0)
			printf("%d\n",s[j]);
			else
			printf("%d ",s[j]);
		}
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=1;
			digui(x+1,num*10+i);
			a[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	digui(1,0);
	return 0;
}

