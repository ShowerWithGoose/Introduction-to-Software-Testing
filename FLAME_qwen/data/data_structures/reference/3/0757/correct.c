#include<stdio.h>
#include<string.h>
char figure[200];
int i=1,start=0,j=0,last=0,x=0,k=0;
int main()
{
	gets(figure);//字符串存数字 
	if(figure[0]=='0')//e带负号
	{
		for(i=2;i<strlen(figure);i++)//找不为0的第一位数字 
		{
			if(figure[i]!='0')
			{
				start=i;//标记为start 
				break;
			} 
		}
		x=start-1;//表示e的多少次幂
		printf("%c",figure[start]);//输出小数点之前的数字start
		last=strlen(figure)-start-1;//表示后面填充的 
		if(last!=0)//判定是否需要小数点
		{
			printf(".");
			for(start=start+1;start<strlen(figure);start++)
			{
				printf("%c",figure[start]);
			}
			printf("e-%d",x);
		}
		else//不需要小数点，有效数字为1 
		{
			printf("e-%d",x);
			
		} 
	}
	else//e不带负号 
	{
		printf("%c",figure[0]);
		for(j=1;j<strlen(figure);j++)
		{
			if(figure[j]=='.')
			{
				x=j-1;
				break;
			}
		}
		printf(".");
		for(k=1;k<strlen(figure);k++)
		{
			if(k!=j)
			printf("%c",figure[k]); 
		} 
		printf("e%d",x);
	}
} 

