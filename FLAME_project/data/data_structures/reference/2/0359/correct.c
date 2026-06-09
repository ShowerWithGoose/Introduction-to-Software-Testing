#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cal(int a,int b,char op)
{
	if(op=='+')return a+b;
	if(op=='-')return a-b;
	if(op=='*')return a*b;
	if(op=='/')return a/b;	
}
int main()
{
	int a[2];
	char b;
	int num;
	char op;
	scanf(" %d",&a[0]);
	scanf(" %c",&b);
	if(b!='=')scanf(" %d",&a[1]);
	while(b!='=')
	{
		if(b=='*'||b=='/')
		{
			a[0]=cal(a[0],a[1],b);
			scanf(" %c",&b);
			if(b!='=')scanf(" %d",&a[1]);
		}
		else
		{
			scanf(" %c",&op);
			if(op=='+'||op=='-'||op=='=')
			{
				a[0]=cal(a[0],a[1],b);
				b=op;
				if(op!='=')scanf(" %d",&a[1]);
			}
			else if(op!='=')
			{
				scanf(" %d",&num);
				a[1]=cal(a[1],num,op);
			}
			else b=op;
		}
	}
	printf("%d",a[0]);
	return 0;
}



