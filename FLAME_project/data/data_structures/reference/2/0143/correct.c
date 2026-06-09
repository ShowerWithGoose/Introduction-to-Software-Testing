#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
int fun(char c,int n,int m)
{
	if(c=='*')
	{
		return n*m;
	}
	if(c=='/')
	{
		return n/m;
	}
	if(c=='+')
	{
		return n+m;
	}
	if(c=='-')
	{
		return n-m;
	}
}
int main(int argc, const char * argv[])
{
	int x=0,y,z;
	char c1='+',c2,c3;
	while(c1!='=')
	{
		scanf("%d %c", &y, &c2);
		while(c2=='*'||c2=='/')
		{
			scanf("%d %c", &z, &c3);
			y=fun(c2,y,z);
			c2=c3;
		}
		x=fun(c1,x,y);
		c1=c2;
	}
	printf("%d",x);
	return 0;
}

