#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int n;
int vis[50];
char* Int2String(int num,char *str);
int fac(int n)
{
	if(n==1)	return 1;
	return n*fac(n-1);
}
void dfs(int x,int num)
{
	int i;
	char string[10]={'\0'};
	if(x==n+1)          
	{
		Int2String(num,string);
		for(i=0;i<10;i++)
		{
			printf("%c ",string[i]);
		}
		//printf("%d\n",num);
		puts("");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(x+1,num*10+i);
			vis[i]=0;
		}
	}
}


int main()
{
	scanf("%d",&n);
	dfs(1,0);
	return 0;
}

char* Int2String(int num,char *str)//10进制 
{
	int i = 0;//指示填充str 
	if(num<0)//如果num为负数，将num变正 
	{
		num = -num;
		str[i++] = '-';
	} 
	//转换 
	do
	{
		str[i++] = num%10+48;//取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0' 
		num /= 10;//去掉最低位	
	}while(num);//num不为0继续循环
	
	str[i] = '\0';
	
	//确定开始调整的位置 
	int j = 0;
	if(str[0]=='-')//如果有负号，负号不用调整 
	{
		j = 1;//从第二位开始调整 
		++i;//由于有负号，所以交换的对称轴也要后移1位 
	}
	//对称交换 
	for(;j<i/2;j++)
	{
		//对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b; 
		str[j] = str[j] + str[i-1-j];
		str[i-1-j] = str[j] - str[i-1-j];
		str[j] = str[j] - str[i-1-j];
	} 
	
	return str;//返回转换后的值 
}



