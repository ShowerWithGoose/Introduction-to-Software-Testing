#include<stdio.h>
int read_num()
{
	int a;
	scanf("%d",&a);
	return a;
}
char read_sym()
{
	char s;
	do
	{
		scanf("%c",&s);
	}while(s==' ');
	return s;
}
int check(char s1,char s2)
{
	if((s1=='*'||s1=='/')||(s2=='+'||s2=='-'))return 1;//先执行第一个运算符
	else if((s2=='*'||s2=='/')&&(s1=='+'||s1=='-'))return 0;//先执行第二个运算符 
}
int main()
{
	int a,b,c;
	char s1,s2;
	a=read_num();
	s1=read_sym();
	if(s1=='='){
		printf("%d",a);
	}
	else{
		b=read_num();
		s2=read_sym();
		if(s2=='='){
			if(s1=='+')a=a+b;
			else if(s1=='-')a=a-b;
			else if(s1=='*')a=a*b;
			else if(s1=='/')a=a/b;
			printf("%d",a);
		}
		else
		{
			while(s2!='='){
				c=read_num();
				if(check(s1,s2)==1){//先执行第一个运算符 
					if(s1=='*')a=a*b;
					else if(s1=='/')a=a/b;
					else if(s1=='+')a=a+b;
					else if(s1=='-')a=a-b;
					b=c;
					s1=s2; 
				}
				else{//先执行第二个 
					if(s2=='*')b=b*c;
					else if(s2=='/')b=b/c;
				}
				s2=read_sym();
			}
			if(s1=='+')a=a+b;
			else if(s1=='-')a=a-b;
			else if(s1=='*')a=a*b;
			else if(s1=='/')a=a/b;
			printf("%d",a);
		}
	}
}



