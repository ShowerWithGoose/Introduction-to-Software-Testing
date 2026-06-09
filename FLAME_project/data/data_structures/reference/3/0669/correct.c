#include<stdio.h>
#include<string.h>
char a[1000];
int point,first,end,sym_F,sym1;
int main()
{
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]=='.') point=i;//点的位置 
		if(a[i]!='-'&&a[i]!='.'&&a[i]!='0'&&sym1==0)//第一次出现有效数字的位置 
		{
			first=i;
			sym1=1;
		}
		if(a[i]=='-') sym_F=1;//正负 
	}
	if(sym_F==0) //正
	{
		if(point==0)
		{
			printf("%c",a[0]);
			if(len>1) putchar('.');
			for(int i=1;i<len;i++)
			{
				printf("%c",a[i]);
			}
			printf("e%d",len-1);
		}
		else if(point>first)//2.5 2.51
		{
			printf("%c.",a[0]);
			for(int i=1;i<point;i++)
			printf("%c",a[i]);
			for(int i=point+1;i<len;i++)
			printf("%c",a[i]);
			printf("e%d",point-1);
		}
		else if(point<first)//0.5 0.51 0.00251
		{
			printf("%c",a[first]);
			if(first!=len-1) putchar('.');
			for(int i=first+1;i<len;i++)
			printf("%c",a[i]);
			printf("e%d",point-first);
		}
	} 
	else //正
	{
		printf("-");
		if(point==0)
		{
			printf("%c",a[1]);
			if(len>2) putchar('.');
			for(int i=2;i<len;i++)
			{
				printf("%c",a[i]);
			}
			printf("e%d",len-2);
		}
		else if(point>first)//2.5 2.51
		{
			printf("%c.",a[1]);
			for(int i=2;i<point;i++)
			printf("%c",a[i]);
			for(int i=point+1;i<len;i++)
			printf("%c",a[i]);
			printf("e%d",point-2);
		}
		else if(point<first)//0.5 0.51 0.00251
		{
			printf("%c",a[first]);
			if(first!=len-1) putchar('.');
			for(int i=first+1;i<len;i++)
			printf("%c",a[i]);
			printf("e%d",point-first);
		}
	} 
}



