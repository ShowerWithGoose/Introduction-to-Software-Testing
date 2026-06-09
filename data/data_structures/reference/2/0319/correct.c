#include <stdio.h>
#include <string.h>

long long getS(long long a,long long b,char c)  //进行加减乘除运算 
{
	if(c=='+')
	return (a+b);
	else if(c=='-')
	return (a-b);
	else if(c=='*')
	return (a*b);
	else 
	return (a/b);
 } 
 
long long getN()   //取数字 
{
 	long long n;
	scanf("%d",&n);
	return n;	
 }
 
char getOp()   // 取运算符并忽视空格 
{
	char c;
	scanf("%c",&c);
	while(c==' ')
		scanf("%c",&c);
	return c;
}

int main()
{
	long long sum,next,last;
	int flag=1;
	char op,nextOp;
	
	sum=getN();   //第一个数字（同时也是前面一部分表达式的值） 
	op=getOp();   //紧接在sum后的运算符 
	
	while(op!='=')
	{
		
		if((op=='+')||(op=='-'))
		{
			if(flag)
			{
			next=getN();   //取下一个数字 
			nextOp=getOp();   //取下一个运算符 
			}
			flag=1;
			if((nextOp=='*')||(nextOp=='/'))
			{
				last=getN();
				next=getS(next,last,nextOp);
				nextOp=getOp();
				flag=0;
				continue;				
			}
			
			else if((nextOp=='+')||(nextOp=='-'))
			{
				sum=getS(sum,next,op);
				op=nextOp;
				continue;
			}
		 	else 
			{
				sum=getS(sum,next,op);
				op=nextOp;
				break;
			}
		}
		else 
		{
			next=getN();
			sum=getS(sum,next,op);
			op=getOp();
		}
	}
	
	printf("%d",sum);
	return 0;
}

