#include<stdio.h>
#include<string.h>
int readnum();   //读数 
char readfuhao();//读符号 
int jisuan(int a,int b,char c);//计算 
int main()
{
	int a[2];//存储两个数  a【0】作为结果 a【1】作为下一个进行计算的数 
	char c[1];//存储运算符
	int num;  //下一个数 
	char fuhao;//下一个操作符 
	a[0]=readnum();
	c[0]=readfuhao(); //初始 a0 和 c0 
	
	if(c[0]!='=')
	{
		a[1]=readnum();//读入下一个数 
	}
	while(c[0]!='=')
	{
		if(c[0]=='*'||c[0]=='/')
		{
			a[0]=jisuan(a[0],a[1],c[0]);//a0 是一直更新的结果 
			c[0]=readfuhao();
			if(c[0]!='=')
			{
				a[1]=readnum();
			}
		}
		else
		{
			fuhao=readfuhao();//下一个符号 
			if(fuhao=='+'||fuhao=='-'||fuhao=='=')
			{
				a[0]=jisuan(a[0],a[1],c[0]);
				c[0]=fuhao;
				if(fuhao!='=')
				a[1]=readnum();
			}
			else if(fuhao!='=')
			{
				num=readnum();
				a[1]=jisuan(a[1],num,fuhao);
			
			}
			else
			c[0]=fuhao;
		}
	}
	 
	
	
	printf("%d\n",a[0]);
	return 0;
}
int readnum()
{
	int num;
	scanf(" %d",&num); //读一个数 
	return num;
}
char readfuhao()
{
	char fuhao;
	scanf(" %c",&fuhao);  
	return fuhao;
}
int jisuan(int a,int b,char c)  //计算 
{
	int result;
	if(c=='+') result=a+b;
	else if(c=='-') result=a-b;
	else if(c=='*') result=a*b;
	else if(c=='/') result=a/b;
	return result;
}

