#include<stdio.h>
#include<string.h>
int main()
{
	char a[105];
	int i,l,f=1,x;
	scanf("%s",a);
	l=strlen(a);
	if(a[0]=='0') f=0;
	for(i=0;i<l;i++)
	if(a[i]=='.') x=i;/////记录小数点的位置 x 
	if(f==1)///看是不是第一种类型：个位非0的数 
	{
		printf("%c.",a[0]);
		for(i=1;i<l;i++)
		{
			if(a[i]=='.') continue;
			else printf("%c",a[i]);
		}//不断向后检索，并判断是否为小数点 
		printf("e%d",x-1);
		return 0;
	}
	else//个位为0的数 
	{
		i=2;
		while(a[i]=='0')
			i++;
		if(i==l-1)//最简单的一种数：全是0除了一个非零小数 
		{
			printf("%ce%d",a[i],x-l+1);
			return 0;
		}
		printf("%c.",a[i]);
		f=i; 
		while(i<=l-2)
		{
			printf("%c",a[++i]);
		}
		printf("e%d",x-f);
		return 0;
	}
}

