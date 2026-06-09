#include<stdio.h>
#include<string.h>
int js(int a,int b,char fuhao)
{
	if(fuhao=='+')
		return a+b;
	else if(fuhao=='-')
		return a-b;
	else if(fuhao=='*')
		return a*b;
	else
		return a/b;
}
int main()
{
	int num[5];
	char c[3];
	scanf(" %d",&num[0]);
	scanf(" %c",&c[0]);
	if(c[0]!='=')
	scanf(" %d",&num[1]);
	while(c[0]!='=')
	{
		if(c[0]=='*'||c[0]=='/')
		{
			num[0]=js(num[0],num[1],c[0]);
			scanf(" %c",&c[0]);
			if(c[0]!='=')
			scanf(" %d",&num[1]);
		}
		else
		{
			scanf(" %c",&c[1]);
			if(c[1]=='+'||c[1]=='-'||c[1]=='=')
			{
				num[0]=js(num[0],num[1],c[0]);
				c[0]=c[1];
				if(c[0]!='=')
				scanf(" %d",&num[1]);
			}
			else if(c[1]!='=')
			{
				scanf(" %d",&num[2]);
				num[1]=js(num[1],num[2],c[1]);
			}
			else 
			c[0]=c[1];
		}
	}
	printf("%d\n",num[0]);
	return 0;
}

