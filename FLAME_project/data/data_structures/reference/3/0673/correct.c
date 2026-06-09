#include<stdio.h>
int main() 
{char a[100]={'\0'};
int i=0,e=0;
	gets(a);
	if(a[0]=='0')
	{
		for(i=2;a[i]!='\0';i++)
		{
		if(a[i]!='0')
		{
			e=i-1;break;
		}
		}
		printf("%c",a[i]);
		if(a[i+1]!='\0')
		printf(".");
		i++;
		for(;a[i]!='\0';i++)
		printf("%c",a[i]);
		printf("e-%d",e);
	}
	else
	{
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='.')
			e=i-1;
		}
		printf("%c.",a[0]);
		for(i=1;a[i]!='\0';i++)
		{
			if(a[i]!='.')
			printf("%c",a[i]);
		}
		printf("e%d",e);
	}
}/*1.小数点前是否只有0
2.小数点前位数/小数点后位数
3.换小数点位置*/ 

