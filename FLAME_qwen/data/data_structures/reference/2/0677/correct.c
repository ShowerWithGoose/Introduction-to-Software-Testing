#include <stdio.h>
#include <string.h>
void func1(char *str,int num[],char *op,int *amt);	//将字符串中的数字和运算符分别提取出来
void func2(char *op,int num[],int amt);	//乘除处理
void func3(char *op,int num[],int amt);	//加减处理
int main() {
	char str[1000];	//完整字符串 
	char op[1000];	//计算符号 
	int num[1000] = {0};	//数字 
	int amt = 0; //amt用于记录数字的个数
	gets(str);
	func1(str,num,op,&amt);
	func2(op,num,amt);
	func3(op,num,amt);
	printf("%d", num[amt]);
	return 0;
}
void func1(char *str,int num[],char *op,int *amt)
{
	*amt=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			num[*amt] = num[*amt]*10+str[i]-'0';
		}else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
			op[(*amt)++] = str[i];
		}
	}
}

void func2(char *op,int num[],int amt)
{
	for(int i=0;i<amt;i++)
	{
		if(op[i]=='*')
		{
			num[i+1] = num[i]*num[i+1];
			num[i]=0;
		}else if(op[i]=='/'){
			num[i+1] = num[i]/num[i+1];
			num[i]=0;
		}
	}
}

void func3(char *op,int num[],int amt)
{
	for(int i=0;i<amt;i++)
	{
		if(op[i]=='+')
		{
			int temp = num[i];
			while(num[i+1]==0)
				i++;
			num[i+1]=temp+num[i+1];
		}else if(op[i]=='-'){
			int temp=num[i];
			while(num[i+1]==0)
				i++;
			num[i+1]=temp-num[i+1];
		}
	 }
}	



