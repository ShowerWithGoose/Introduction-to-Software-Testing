#include<stdio.h>
#include<string.h>
#include<ctype.h>
//char a[200];
//char b[200];
//int c[200];//存放数字 
//char d[200];//存放运算符号 
//int k=0;
//int duoweishu;
//void jishuqi(char b[],int k2)//将数字和运算符号分开放在两个数组里面 
//{
//	int i,j,l,m;
//	for(i=0,j=0,l=0,m=0;i<=k2;i++)
//	{
//		duoweishu=0;
//		while(isdigit(b[i]) && b[i+1]!='=')
//		{
//			duoweishu=duoweishu*10+b[i]-'0';
//			if(!isdigit(b[i+1]))
//			{
//				break;
//			}
//			i++;
//		}
//		c[l]=duoweishu;
//		l++;
//		if(!isdigit(b[i]) && b[i]!='=')
//		{
//			d[m]=b[i];
//			m++;
//		}
//	}
//}
int readnum()
{
	int num;
	scanf(" %d",&num);
	return num;
}
char readc()
{
	char c;
	scanf(" %c",&c);//表达式中可以有空格 所以就在格式输入的最前面加一个空格过滤掉 
	return c;
}
int jisuan(char c,int x,int y)
{
	int z;
	switch(c)
	{
		case '+':
			z=x+y;
			break;
		case '-':
			z=x-y;
			break;
		case '*':
			z=x*y;
			break;
		case '/':
			z=x/y;
			break;
	}
	return z;
}

int main()
{
	int a[2];//要运算的两个数 
	char b[1];//运算符号 
	char c;
	int num;
	
	a[0]=readnum();
	b[0]=readc();
	if(b[0]!='=')
	{
		a[1]=readnum();
	} 
	while(b[0]!='=')
	{
		if(b[0]=='*' || b[0]=='/')
		{
			a[0]=jisuan(b[0],a[0],a[1]);
			b[0]=readc();
			if(b[0]!='=')
			{
				a[1]=readnum();
			}
		}
		else
		{
			c=readc();
			if(c=='+' || c=='-' || c=='=')
			{
				a[0]=jisuan(b[0],a[0],a[1]);
				b[0]=c;
				if(c!='=')
				{
					a[1]=readnum();
				}
			}
			else if(c=='*' || c=='/')
			{
				num=readnum();
				a[1]=jisuan(c,a[1],num);
			}
		}
	}
	printf("%d",a[0]);
	return 0;
}






