#include<stdio.h>
#include<math.h>
#include<string.h>
int calculate(int c,char d,int e)//此函数是为了计算式子
{
    if(d=='*')
        return c*e;
    if(d=='/')
        return c/e;
    if(d=='+')
        return c+e;
    if(d=='-')
        return c-e;
}

int number()
{
    int a;//a是输入的数字
    scanf("%d",&a);
    return a;
}
char ch()
{
    char b;//b为输入的运算符
    do
    {
        scanf("%c",&b);
    }while(b==' ');
    return b;
}
int main ()
{
	char m,n;
	int x,y,z;
	x=number();
	m=ch();
	if(m=='=') printf("%d",x);
	else {
		y=number();
		n=ch();
		if(n=='=')
		{
			if(m=='+') printf("%d",x+y);
			if(m=='-') printf("%d",x-y);
			if(m=='*') printf("%d",x*y);
			if(m=='/') printf("%d",x/y);
		}
		else 
		{
			while(n!='=')
			{
			z=number();
			if(((m=='*'||m=='/')&&(n=='+'||n=='-'))||((m=='+'||m=='-')&&(n=='+'||n=='-'))||((m=='*'||m=='/')&&(n=='*'||n=='/')))
			{
				if(m=='*') x=x*y;
				if(m=='/') x=x/y;
				if(m=='+') x=x+y;
				if(m=='-') x=x-y;
				y=z;
				m=n;
			}
			else if((n=='*'||n=='/') &&(m=='+'||m=='-'))
			{
				if(n=='*') y=y*z;
				if(n=='/') y=y/z;
			}
			n=ch();
			}
			
			printf("%d",calculate(x,m,y));
		}
	}
	
	return 0	;
}

