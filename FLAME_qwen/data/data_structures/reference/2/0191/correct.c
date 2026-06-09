#include <stdio.h>
#include <string.h>
int readnum()
{
	int num;
	scanf(" %d",&num);
	return num;
}
char readsymbol()
{
	char symbol;
	scanf(" %c",&symbol);
	return symbol;
}
int cal(int a , int b , char c )
{
	int num;
	switch(c)
	{
		case '+' : num=a+b; break;
		case '-' : num=a-b; break;
		case '*' : num=a*b; break;
		case '/' : num=a/b; break;
	}
	return num;
}
int main()
{
	int a[3];
	a[0]=readnum();
	char b[2],temp;
	b[0]=readsymbol();
	if(b[0]!='=')
	{
		a[1]=readnum();
	}
	while(b[0]!='=')
	{
		if((b[0]=='*')||(b[0]=='/'))
		{
			a[0]=cal(a[0],a[1],b[0]);
			b[0]=readsymbol();
			if(b[0]!='=')
			a[1]=readnum();
		}
		else
		{
			b[1]=readsymbol();
			
			if((b[1]=='*')||(b[1]=='/'))
			{
			    a[2]=readnum();
				a[1]=cal(a[1],a[2],b[1]);
			}
			else if((b[1]=='+')||(b[1]=='-')||(b[1]=='='))
			{
				a[0]=cal(a[0],a[1],b[0]);
				if(b[1]!='=')
				a[1]=readnum();
				b[0]=b[1];
			}
			else 
			b[0]=b[1];
		}
	}
	printf("%d",a[0]);
	return 0;
 } 

