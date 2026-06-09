#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
int main()
{
	char a[101];
	gets(a);
	int len;
	len=strlen(a);//找到第一个非零的数 输出其剩余部分
	int i,j,k,feiling,xiaoshudian,x;
	for(i=0;i<len;i++)
	{
		if((a[i]!='0')&&(a[i]!='.'))
		{
			feiling=i;
			break;
		}
	 } 
	 for(i=0;i<len;i++)
	{
		if(a[i]=='.')
		{
			xiaoshudian=i;
			break;
		}
	 } 
	if(feiling<xiaoshudian)//2.3
	{
		x=xiaoshudian-feiling-1;
		
	}
	else
	{
		x=xiaoshudian-feiling;//0.1
	}
	for(i=feiling;i<len;i++)
		{
			if(i==xiaoshudian)
			{
				i++;
			}
			printf("%c",a[i]);
			if((i==feiling)&&(i!=len-1))
			{
				printf(".");
			}
		}
	printf("e%d\n",x);
	
	
	return 0;
}


