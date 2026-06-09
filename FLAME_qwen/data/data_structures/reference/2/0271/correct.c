#include<stdio.h>
#include<string.h>
int calculate(int a,int b,char c);
int readnum();
char readcharacter();
int main()
{
	int a[5];
	char b;
	int num;
	char ch;
	a[0]=readnum();
	b=readcharacter();
	if(b!='=') a[1]=readnum();
	while(b!='=')
	{
		if(b=='*'||b=='/')
		{
			a[0]=calculate(a[0],a[1],b);
			b=readcharacter();
			if(b!='=') a[1]=readnum();
		}
		else
		{
			ch=readcharacter();
			if(ch=='+'||ch=='-'||ch=='=')
			{
				a[0]=calculate(a[0],a[1],b);
				b=ch;
				if(ch!='=') a[1]=readnum();
			}
			else if(ch!='=')
			{
				num=readnum();
				a[1]=calculate(a[1],num,ch);
			}
			else b=ch;
		}
	}
	printf("%d\n",a[0]);
	return 0;
	
	
}
int readnum()
{
	int n;
	scanf(" %d",&n);
	return n;
}
char readcharacter()
{
	char c;
	scanf(" %c",&c);
	return c;	
}
int calculate(int a,int b,char c)
{
	if(c=='+')	return a+b;
	else if(c=='-')	return a-b;
	else if(c=='*') return a*b;
	else return a/b;
}


