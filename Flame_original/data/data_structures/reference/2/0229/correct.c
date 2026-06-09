#include<stdio.h>
int cll(int a,int b,char s);
int shuzi();
char zifu();
int main()
{
	int a[2],t;
	char s1,s2;
	a[0]=shuzi();
	s1=zifu();
	if(s1!='=')
		a[1]=shuzi();
	while(s1!='=')
	{
		if(s1=='*'||s1=='/')
		{
			a[0]=cll(a[0],a[1],s1);
			s1=zifu();
			if(s1!='=')
				a[1]=shuzi();
		} 
		else
		{
			s2=zifu();
			if(s2=='+'||s2=='-'||s2=='=')
			{
				a[0]=cll(a[0],a[1],s1);
				s1=s2;
				if(s2!='=')
					a[1]=shuzi();
			}
			else if(s2!='=')
			{
				t=shuzi();
				a[1]=cll(a[1],t,s2);
			}
			else
				s1=s2;
		}
	}
	printf("%d\n",a[0]);
	return 0;
}
int cll(int a,int b,char s)//定义运算过程 
{
	int m;
	if(s=='+')
		m=a+b;
	else if(s=='-')
		m=a-b;
	else if(s=='*')
		m=a*b;
	else if(s=='/')
		m=a/b;
	return m;
}
int shuzi()
{
	int x;
	scanf(" %d",&x);
	return x;
}
char zifu()
{
	char s;
	scanf(" %c",&s);
	return s;
}

