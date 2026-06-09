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
	long long result,temp,next;
	int flag=1;
	char c,nextOp;
	
	result=getN();   //第一个数字（同时也是前面一部分表达式的值） 
	c=getOp();   //紧接在sum后的运算符 
	
	while(c!='=')
	{
		
		if((c=='+')||(c=='-'))
		{
			if(flag)
			{
			temp=getN();   //取下一个数字 
			nextOp=getOp();   //取下一个运算符 
			}
			flag=1;
			if((nextOp=='*')||(nextOp=='/'))
			{
				next=getN();
				temp=getS(temp,next,nextOp);
				nextOp=getOp();
				flag=0;
				continue;				
			}
			
			else if((nextOp=='+')||(nextOp=='-'))
			{
				result=getS(result,temp,c);
				c=nextOp;
				continue;
			}
		 	else 
			{
				result=getS(result,temp,c);
				c=nextOp;
				break;
			}
		}
		else 
		{
			temp=getN();
			result=getS(result,temp,c);
			c=getOp();
		}
	}
	
	printf("%d",result);
	return 0;
}

