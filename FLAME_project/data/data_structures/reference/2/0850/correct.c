#include<stdio.h>
int rdnum()
{
	int num;
	scanf(" %d",&num);
	return num;
}
char rdtype()
{
	char c;
	scanf(" %c",&c);
	return c;
}
int cal(int a,int b,char c)
{
	if(c=='*')
	return a*b;
	else if(c=='/')
	return a/b;
	else if(c=='+')
	return a+b;
	else
	return a-b;
} 
int main()
{
	int num[2];char type[1];
	scanf("%d",&num[0]);
	type[0]=rdtype();
	if(type[0]=='=')
	{
		printf("%d",num[0]);
		return 0;
	}
	num[1]=rdnum();
	while(type[0]!='=')
	{
		if(type[0]=='*'||type[0]=='/')
		{
			num[0]=cal(num[0],num[1],type[0]);
			type[0]=rdtype();
			if(type[0]!='=')
			num[1]=rdnum(); 
		}
		else
		{
			int nextnum;
			char nexttype;
			nexttype=rdtype();
			if(nexttype=='+'||nexttype=='-')
			{
				num[0]=cal(num[0],num[1],type[0]);
				num[1]=rdnum();
				type[0]=nexttype;
			}
			else if(nexttype=='*'||nexttype=='/') 
			{
				nextnum=rdnum();
				num[1]=cal(num[1],nextnum,nexttype);
			}
			else//nexttype='='
			{
				num[0]=cal(num[0],num[1],type[0]);
				type[0]=nexttype;
			}
		}
	}
	printf("%d",num[0]);
	return 0;
}

