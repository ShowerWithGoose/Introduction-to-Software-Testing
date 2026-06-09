#include<stdio.h>

int read(){    //快读，读入速度显著快于cin,scanf，但只能读整数
 int x=0,f=1;char ch=getchar();//x为读入整数的绝对值，f为读入数的符号
 while(ch<'0'||ch>'9'){//读取符号
     if(ch=='-') f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9'){//读取数
     x=x*10+ch-'0';ch=getchar();}
 return x*f;//返回数×符号
}

int s[5005];
int size;
void pop()
{
	size--;
}
void push(int x)
{
	s[++size]=x;
}
int top()
{
	return s[size--];
}

int main()
{
	while(1)
	{
		int x=read();
		if(x==1)
		{
			int y=read();
			size==100?printf("error "):push(y);
		}
		else if(x==0)
		{
			size?printf("%d ",top()):printf("error ");
		}
		else if(x==-1)
			return 0;
	}
	return 0;
}

