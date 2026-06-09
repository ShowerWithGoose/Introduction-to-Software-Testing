#include<stdio.h>
int main()
{
	int a[1000]={0},x=0,n,y;
	char b[1000];
	while(scanf("%d %c",&a[x],&b[x])!=-1)
	x++;
	y=x;
	for(n=0;b[n]!='=';n++)
	{
		if(b[n]=='*')
		{
		a[n+1]=a[n]*a[n+1];
		a[n]=50000;
	    }
		if(b[n]=='/')
		{
			a[n+1]=a[n]/a[n+1];
			a[n]=50000;
		}
	}
	for(n=0;b[n]!='=';n++)
	{
		x=n+1;
		while(a[x]==50000)
		x++;
		if(b[n]=='+')
		a[x]=a[x]+a[n];
		if(b[n]=='-')
		a[x]=a[n]-a[x];
	}
	printf("%d",a[y-1]);
	return 0;
}

