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
	long long ans,temp,last;
	int op_flag=1;
	char op,next;
	
	ans=getN();   //第一个数字（同时也是前面一部分表达式的值） 
	op=getOp();   //紧接在sum后的运算符 
	
	while(op!='=')
	{
		
		if((op=='+')||(op=='-'))
		{
			if(op_flag)
			{
			temp=getN();   //取下一个数字 
			next=getOp();   //取下一个运算符 
			}
			op_flag=1;
			if((next=='*')||(next=='/'))
			{
				last=getN();
				temp=getS(temp,last,next);
				next=getOp();
				op_flag=0;
				continue;				
			}
			
			else if((next=='+')||(next=='-'))
			{
				ans=getS(ans,temp,op);
				op=next;
				continue;
			}
		 	else 
			{
				ans=getS(ans,temp,op);
				op=next;
				break;
			}
		}
		else 
		{
			temp=getN();
			ans=getS(ans,temp,op);
			op=getOp();
		}
	}
	
	printf("%d",ans);
	return 0;
}

