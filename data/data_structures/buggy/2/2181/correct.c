#include<stdio.h>
#include<math.h> 
#include<string.h>
#include<stdlib.h>

int f(int a, char x, int b); 

int a, b, c;
char x, y;
int n, i, j;

int main()
{
	scanf("%d",&a);
	while((x=getchar())==' ') {};
	if(x=='=')
	{
		printf("%d",a);
	}
	else
	{
		scanf("%d",&b);
		while((y=getchar())==' ') {};
		while(y!='=')
		{
			scanf("%d",&c);
			if((x=='+'||x=='-')&&(y=='*'||y=='/'))
			{
				b=f(b, y, c);
			}
			else
			{
			a=f(a, x, b);
			b=c;
			x=y;	
			}
			while((y=getchar())==' ') {};
		}
		printf("%d",f(a, x, b));
	}


return 0;	
}

int f(int a, char x, int b)
{
	if(x=='+')
	{
		return (a+b);
	}
	if(x=='-')
	{
		return (a-b);
	}
	if(x=='*')
	{
		return (a*b);
	}
	if(x=='/')
	{
		return (a/b);
	}
}




