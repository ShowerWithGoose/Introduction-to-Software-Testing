#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>

char s[110];
int main()
{	int i,j; 
	char *pos=NULL;//确定小数点的位置 

	scanf("%s",s);
	int len=strlen(s);
	pos=strchr(s,'.');//char *strchr(const char *str, int c),返回字符指针 
	if(pos==NULL)//没有查找到小数点,即是纯整数
	{
		printf("%c",s[0]);
		printf(".");
		for(i=1;i<len;i++)
		{
			printf("%c",s[i]);
		}
		printf("e%d",len-1);
		  
	}
	 
	else if(pos-s==1)//如果是整数不大于10 
	{
		if(s[0]=='0')//判断整数部分是否为0 
		{
			for(i=2;i<len;i++)
			{
				if(s[i]!='0') 
				{
					break;
				}
			}
			
			if(i==len-1) //只有一位非零位。指数是负数，底数无小数点 
			{				
					printf("%c",s[i]);
					printf("e-%d",len-2);
			}
			
			else //指数是负数，底数有小数点 
			{
				printf("%c",s[i]);
				printf(".");
				for(j=i+1;s[j]!='\0';j++)
					printf("%c",s[j]);
			
				printf("e-%d",i-1);
			}
		}
		else  //底数大于等于1小于10，指数为0 
		{
			s[len]='e';
			s[len+1]='0';
			puts(s);
		} 
	}
	else //底数大于等于10 的情况，指数为正数 
	{
		j=pos-s;
		printf("%c",s[0]);
		printf(".");
		for(i=1;s[i]!='\0';i++)
		{
			if(s[i]!='.')
			printf("%c",s[i]);
		}
		printf("e%d",j-1);
	}

return 0;
}


