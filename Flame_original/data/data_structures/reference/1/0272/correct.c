#include <stdio.h>
int a[11][3628810];
int jc(int n)
{
	int sum=1;
	for(int i=n;i>=1;i--)
	{
		sum*=i;
	}
	return sum;
}
int jw(int y,int n)
{
	if(y%n>0)
	return y/n+1;
	else
	return y/n;
}
int wc(int y,int n)
{
	if(y%n==0)
	return n;
	else
	return y%n;
}
int cal(int n,int x,int y)
{
	if(n==1&&x==1&&y==1)
	return 1;
	else if(n==2&&x==1&&y==1)
	return 1;
	else if(n==2&&x==1&&y==2)
	return 2;
	else if(n==2&&x==2&&y==1)
	return 2;
	else if(n==2&&x==2&&y==2)
	return 1;
	else if(n>2&&x==1)
	return jw(y,jc(n-1));
	else if(n>2&&x>1&&y<=jc(n-1))
	return cal(n-1,x-1,y)+1;
	else if(n>2&&x>1&&y>n-1)
	{
		if(cal(n,x,wc(y,jc(n-1)))<=jw(y,jc(n-1)))
		return cal(n,x,wc(y,jc(n-1)))-1;
		else
		return cal(n,x,wc(y,jc(n-1)));
	}
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(y=1;y<=jc(n);y++)
	{
		for(x=1;x<=n;x++)
		{
			printf("%d ",cal(n,x,y));
		}
		putchar('\n');
	}
	
	
	return 0;
}



