#include <stdio.h>
int jisuan(int a,int b,char c);
int shu();
char fu();
int main()
{
int a[2],num;
char b[1],c;
a[0]=shu();
b[0]=fu();
if(b[0]!='=')
{
    a[1]=shu();
}
while(b[0]!='=')
{
	if(b[0]=='+'||b[0]=='-'||b[0]=='=')
	{
		c=fu();	
	if(c=='+'||c=='-'||c=='=')
	{
	
	    a[0]=jisuan(a[0],a[1],b[0]);
	    b[0]=c;
		if(b[0]!='=')
	    {
         a[1]=shu();
        }	
	}
	else if(c!='=')
	{
		num=shu();
		a[1]=jisuan(a[1],num,c);
	}
	else 
		b[0]=c;
	}
	else
	{
		a[0]=jisuan(a[0],a[1],b[0]);
		b[0]=fu();
		if(b[0]!='=')
	    {
        a[1]=shu();
        }
	}
}
printf("%d",a[0]);
return 0;
}
int jisuan(int a,int b,char c)
{
	int r;
	if(c=='+')
	{
		r=a+b;
	}
	else if(c=='-')
	{
		r=a-b;
	}
	else if(c=='*')
	{
		r=a*b;
	}
	else
	{
		r=a/b;
	}
	return r;
}
int shu()
{
	int a;
	scanf(" %d",&a);
	return a;
}
char fu()
{
	char c;
	scanf(" %c",&c);
	return c;
}

