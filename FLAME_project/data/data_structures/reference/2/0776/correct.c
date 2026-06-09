#include <stdio.h>
#include <string.h>

#define MAXN 100000

char s[MAXN],str[MAXN],op1,op2,*p;
long long a,b,c,answer;

long long cal()
{
	long long ans=0;
	while(*p>='0'&&*p<='9')
	{
		ans=ans*10+(*p-'0');
		p++;
	}
	return ans;
}

long long fml(long long x,long long y,char op)
{
	long long ans;
	switch(op)
	{
		case '+': ans=x+y;break;
		case '-': ans=x-y;break;
		case '*': ans=x*y;break;
		case '/': ans=x/y;break;
	}
	return ans;
}

int main()
{
	gets(s);
	long long num=0;
	answer=0;
	for(long long i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		{
			str[num]=s[i];
			num++;
		}
	}
	p=&str[0];
	a=cal();
	op1=*p;
	if(op1=='=')
	{
		printf("%lld",a);
		return 0;
	}
	p++;
	b=cal();
	while(*p!='=')
	{
		op2=*p;
		if(((op1=='+')||(op1=='-'))&&((op2=='*')||(op2=='/')))//op2优先级更高 
		{
			p++;
			c=cal();
			b=fml(b,c,op2);
		}
		else//op1优先级更高或二者相同
		{
			a=fml(a,b,op1);
			op1=op2;
			p++;
			b=cal();
		} 
	}
	answer=fml(a,b,op1);
	printf("%lld",answer);
	return 0;
 }

/*思路
1去掉空格
2读入数字a（用函数计算）
3读入字符op1
4读入字符b（用函数计算）
5读入字符op2
6将op2与op1进行比较
	1：op1优先级高or两者优先级相同：计算a op1 b，将所得存为a,将op2的值赋给op1 
	2：op2优先级高：读入c（用函数计算），计算b op2 c，将所得存为b,找到下一个op2 
7重复5-6，直至遇见‘=’，输出答案 
*/

