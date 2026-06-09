#include<stdio.h>
#include<string.h>
char str[10000],fu[10000];
int num[10000];
int main()
{
	fgets(str,10000,stdin);
	int i,j,k;
	for(i=0,j=0;i<strlen(str)+1;i++)
	if(str[i]!=' ')  str[j++]=str[i];//去除数组中的空格 
	int p=0,q=0;
	for(i=0;i<strlen(str)+1;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			num[p]=num[p]*10+str[i]-'0';
		}
		else
		{
			fu[q++]=str[i];
			p++;
		}
	}//将数与符号分离并存在两个数组中 
	for(i=0;i<strlen(fu);i++)
	{
		if(fu[i]=='*')
		{
			num[i+1]=num[i]*num[i+1];
			num[i]=-1;
		}
		if(fu[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=-1;
		}
	}//算乘除 ，同时把算过的数字记为0 
	int num1[1000]={0};
	char fu1[1000]="\0";
	for(i=0,j=0,k=0;i<strlen(fu);i++)
	{
		if(num[i]!=-1) num1[j++]=num[i]; //去掉算过的数字 (-1)
		if(fu[i]=='+'||fu[i]=='-') fu1[k++]=fu[i];//保留加和减 
		}	
	int sum=num1[0]; 
	for(i=0;i<strlen(fu1);i++)
	{
		if(fu1[i]=='+')
		{
			sum=sum+num1[i+1];
		}
		if(fu1[i]=='-')
		{
			sum=sum-num1[i+1];
		}
	}//将剩下的数加起来 
	printf("%d",sum);
	return 0;
 }



