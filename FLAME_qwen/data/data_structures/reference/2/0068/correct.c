#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#define eps 1e-8
#define pi 3.14
#define eof EOF
int numberc();
char operatc();
int calculate(int a,int b,char c);
int judeg(char a,char b);

int main()
{
	int one,two,three;
	int flag; int sum;
	char a,b;
	one=numberc();
	a=operatc();
	
	if(a=='=')//500=的情况 
	printf("%d",one);
	else
	{
		two=numberc();
		b=operatc();
		if(b=='=')//20+50=70的情况； 
		{
			sum=calculate(one,two,a);
			printf("%d",sum);
		}
		else//正常情况 
		{
			while(b!='=')
			{
				three=numberc();
				flag=judeg(a,b);
				if(flag==1)//前边先
				{
					one=calculate(one,two,a);
					a=b;
					two=three;
			 	} 
			 	else if(flag==-1)
			 	{
			 		two=calculate(two,three,b);
				}
				b=operatc();
			}
			sum=calculate(one,two,a);
			printf("%d",sum);
		}	
}}

int numberc()
{
	int a;
	scanf("%d",&a);
	return a;
}
char operatc()
{
	char c;
	while(1)
	{
	scanf("%c",&c);
	if(c=='+'||c=='-'||c=='/'||c=='*'||c=='=')
	return c;}
}
int calculate(int a,int b,char c)
{
	if(c=='+')
	return a+b;
	if(c=='-')
	return a-b;
	if(c=='*')
	return a*b;
	if(c=='/')
	{
	if(b==0)
	return a;
	else
	return a/b;}
}
int judeg(char a,char b)
{
	if(a=='*'||a=='/')
	return 1;
	else
	{
		if(b=='*'||b=='/')
		{
			return -1;
		}
		else 
		return 1;
	}
	
}




