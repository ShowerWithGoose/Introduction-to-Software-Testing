#include<stdio.h>
#include<string.h>
int main()
{	char num[105];
	gets(num);
	int i,sum=0,flag1,flag2,e,flag;
	for(i=0;i<=strlen(num)-1;i++)
	if(num[i]-48>=1&&num[i]-48<=9)
	sum++;
	for(i=0;i<=strlen(num)-1;i++)
	{	if(num[i]-48>=1&&num[i]-48<=9)
		flag1=i,flag=num[i]-48;
		if(num[i]-48>=1&&num[i]-48<=9)
		break;
	}
	for(i=0;i<=strlen(num)-1;i++)
	{	if(num[i]=='.')
		flag2=i;
		if(num[i]=='.')
		break;
	}
	if(flag2>flag1)
	e=flag2-flag1-1;
	else
	e=flag2-flag1;
	if(sum==1)
	printf("%de%d",flag,e);
	else
	{	printf("%d.",flag);
		for(i=flag1+1;i<=strlen(num)-1;i++)
		if(num[i]!='.')
		printf("%c",num[i]);
		printf("e%d",e);
	}
	return 0;
} 

