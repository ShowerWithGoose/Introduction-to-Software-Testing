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
	int a=0,b,c;
	char c1='+',c2,c3;
	while(c1!='=')
	{
		scanf("%d %c", &b, &c2);
		while(c2=='*'||c2=='/')
		{
			scanf("%d %c", &c, &c3);
			b=fun(c2,b,c);
			c2=c3;
		}
		a=fun(c1,a,b);
		c1=c2;
	}
	printf("%d",a);
	return 0;
}

