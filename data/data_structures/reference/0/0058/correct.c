#include<stdio.h>
#include<string.h>
#include<ctype.h> 
void main()
{
	char a[1000];
	char b;
	int i=0;
	gets(a);//读入字符串 
	int len=strlen(a);//得到字符串长度 

	for(i=0;i<len;i++)
	{
		if(a[i]=='-')
		{
			if(isupper(a[i-1])&&isupper(a[i+1]))// 判断是不是大写字母 
			{
				if(a[i-1]<a[i+1])//判断是不是按顺序的 
				{
					for(b=a[i-1]+1;b<a[i+1];b++)//是就把中间的也输出
					{ 
						printf("%c",b);
					}
				}
				else//不是就直接输出 
				{
					printf("%c",a[i]);
				}
			}
			else if(islower(a[i-1])&&islower(a[i+1]))//判断是不是小写字母 
			{
				if(a[i-1]<a[i+1])//判断是不是按顺序的 
				{
					for(b=a[i-1]+1;b<a[i+1];b++)//是就把中间的也输出
					{
						printf("%c",b);
					}
				}
				else//不是就直接输出
				{
					printf("%c",a[i]);
				}
			}
			else if(isdigit(a[i-1])&&isdigit(a[i+1]))//判断是不是数字 
			{
				if(a[i-1]<a[i+1])//判断是不是按顺序的 
				{
					for(b=a[i-1]+1;b<a[i+1];b++)//是就把中间的也输出
					{
						printf("%c",b);
					}
				}
				else//不是就直接输出
				{
					printf("%c",a[i]);
				}
			
			}
			else//对于没有按顺序的直接输出 
			{
				printf("%c",a[i]);
			}
		}
		else//对于不是-的直接输出 
			printf("%c",a[i]);
	}
}

	

