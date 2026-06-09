#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
int main()
{
	char s[120],*p,*q,*r;
	int i=0,flag=0,a=0,b=0,o=0;
	gets(s);
	for(p=s;*p!='.'&&*p!='\0';p++)
	{
		a++;
	}
	for(r=s+strlen(s)-1;*r!='.'&&r>=s;r--)
	{
		if(*r=='0'&&flag==0)b++;
		else if(*r!='0')
		{
			flag=1;
			break;
		}
	}
	if(a==1&&s[0]=='0'){
		flag=0;
	for(p++;*p!='\0';p++)
	{
		if(*p=='0'&&flag==0)
		{
			o++;
		}
		else if(*p!='0')
		{
			flag=1;
			break;
		}
	}
	printf("%c",*p);
	if(p==r)
	{
		goto l;
	}
	else{
	printf(".");
	for(q=p+1;q!=r+1;q++)
	{
		printf("%c",*q);
	}
	l:printf("e-%d",o+1);
	}}
	else if(a==1&&s[0]!='0')
	{
		for(q=s;q!=r+1;q++)
		{
			printf("%c",*q);
		}
		printf("e0");
	}
	else if(a!=1)
	{
		printf("%c",s[0]);
		if(p==r+a)
		goto m;
		printf(".");
		m:for(q=s+1;q!=r+1;q++)
		{
			if(q==p)continue;
			printf("%c",*q);
		}
		printf("e%d",a-1);
	}
	return 0;
}





