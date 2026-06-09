#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define ull unsigned long long



int num[100];
char op[100]={'#'};
int ntop=0;
int otop=1;

int pri(char s);
char s[100];
int main()
{
	
	char ch;
	ch=getchar();
	
	while(op[otop-1]!='#'||ch!='=') //&&后面的条件可以将运算符栈中的元素全部用完 
	{
		
		int flag=0;
		int w=0;
		if(ch==' ')
		{
			ch=getchar();
			continue;
		}
		while(isdigit(ch))
		{
			flag=1;
			w=w*10+ch-'0';
			ch=getchar();
		}
		if(flag)
		{
			num[ntop++]=w;
		}
		else
		{
			int prio=pri(ch);
			if(prio == 1)
			{
				op[otop++]=ch;
				ch=getchar();
			}
				
			else
			{
				char x=op[--otop];
				int b=num[--ntop];
				int a=num[--ntop];
				if(x=='+')
					a=a+b;
				else if(x=='-')
					a=a-b;
				else if(x=='*')
					a=a*b;
				else if(x=='/')
					a=a/b;
				num[ntop++]=a;
				//这里不需要getchar 让此时的ch返回到while中继续循环 
			}
		}
		
	}
	printf("%d",num[0]);
	return 0;
}
int pri(char s)
{
	if(s=='+'||s=='-')
	{
		if(op[otop-1]=='#')
			return 1;
		else
			return -1;
	}
	if(s=='*'||s=='/')
	{
		if(op[otop-1]=='+'||op[otop-1]=='-'||op[otop-1]=='#')
			return 1;
		else
			return -1;
	}
	
}

