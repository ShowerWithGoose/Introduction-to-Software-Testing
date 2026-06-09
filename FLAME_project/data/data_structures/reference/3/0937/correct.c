#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[107]; 
int main()
{
	scanf("%s",s);
	int len=strlen(s),point=-1;
	for(int i=0;i<len;i++)//寻找小数点位置 
	{
		if(s[i]=='.')
		{
			point=i;
			break;
		}
	}
	if(point==-1)//没有小数点 
	{
		if(len==1)//个位数字
		{
			printf("%ce0",s[0]);
			return 0;
		} 
		else//数字>=10
		{
			printf("%c",s[0]);
			int k=len-1;
			for(;k>0&&s[k]=='0';)//寻找最后一位不为0的位置
			{
				k--;
			}//s[k]是最后一位不为0的位数 
			if(k!=0)
			{
				printf(".");
				for(int i=1;i<=k;i++)
				{
					printf("%c",s[i]);
				}
			}
			printf("e%d",len-1);
			return 0;
		} 
	}
	else//有小数点，在s[point]位置
	{
		if(point==1&&s[0]!='0')//1<=x<10
		{
			for(int i=0;i<len;i++)
			{
				printf("%c",s[i]);
			}
			printf("e0");
			return 0;
		}
		else if(point==1)//0<x<1
		{
			int m;
			for(m=2;m<len;m++)//寻找小数点后第一个不为0的位数 
			{
				if(s[m]!='0')
				break;
			}
			printf("%c",s[m]);
			int k=len-1;
			for(;k>=m&&s[k]=='0';)
			{
				k--;
			}
			if(k!=m)
			{
				printf(".");
				for(int i=m+1;i<=k;i++)
				{
					printf("%c",s[i]);
				}
			}
			printf("e-%d",m-1);
			return 0;
		}
		else//x>=10
		{
			printf("%c.",s[0]);
			for(int i=1;i<point;i++)
			{
				printf("%c",s[i]);
			}
			for(int i=point+1;i<len;i++)
			{
				printf("%c",s[i]);
			}
			printf("e%d",point-1);
			return 0;
		}
	} 
}

