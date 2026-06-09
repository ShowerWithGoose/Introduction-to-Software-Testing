#include <stdio.h> 
int cal(int a,int b,char op)
{if(op=='+')
return a+b;
if(op=='-')
return a-b;
if(op=='*')
return a*b;
if(op=='/')
return a/b;
}
int num()
{int x;
	scanf(" %d",&x);
	return x;
}
char op()
{char y;
	scanf(" %c",&y);
	return y;
}
int main()
{int m[2],n[1];
char nextop;
int nextnum;
m[0]=num();
n[0]=op();
if(n[0]!='=')
{m[1]=num();
	while(n[0]!='=')
	{	
	if(n[0]=='*'||n[0]=='/')
	{m[0]=cal(m[0],m[1],n[0]);
	n[0]=op();
	if (n[0]!='=')
	m[1]=num();
	}
	else
	{nextop=op();
	if(nextop=='+'||nextop=='-'||nextop=='=')
	{m[0]=cal(m[0],m[1],n[0]);
	n[0]=nextop;
	if(nextop!='=')
	m[1]=num();
	}
	else
	{nextnum=num();
	m[1]=cal(m[1],nextnum,nextop);
	}
	}
	
	}
	
}
	
	printf("%d",m[0]);
	return 0;
}

