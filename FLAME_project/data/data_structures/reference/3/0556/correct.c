#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>


char s[105];

int main()
{
	
	gets(s);
	char * p=NULL;//指向小数点的指针 
	int len=strlen(s);//数组长度
	int i;
	int x;//0.000x 中x的数组下表位置 
	
	p=strchr(s,'.');
	int l=p-s; //小数点前数字的个数 
	if(p-s==1)//小数点前有一位数字
	{
		if(s[0]=='0')//小数点前的数字为0 
		{
			for(i=2;i<len;i++)
			{
				if(s[i]!='0')
				{
					x=i;
					break;
				}
			}
			if(x==len-1)//x所在位置就是字符串的最后一位
			{
				printf("%c",s[x]);
				printf("e-%d",x-1);
			}
			else//比如0.000023778 
			{
				printf("%c",s[x]);
				printf(".");
				for(i=x+1;i<len;i++)
					printf("%c",s[i]);
				printf("e-%d",x-1);
			}
		}
		
		else//小数点前的数字为1~9的自然数
		{
			for(i=0;i<len;i++)
				printf("%c",s[i]); //直接全部输出即可
			printf("e0");
		}
	}
	
	else//小数点前的数大于10  2333.3->2.3333
	{
		printf("%c.",s[0]);
		for(i=1;i<l;i++)
			printf("%c",s[i]);
		for(i=l+1;i<len;i++)
			printf("%c",s[i]);
		printf("e%d",l-1);
	}
		



	
	
	
	
}

