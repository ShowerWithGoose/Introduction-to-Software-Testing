#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <ctype.h>
int part[1000];
char b[1000] ;
void cancel(char s[]) 
{
	int i,j;
	int len=strlen(s);
	for(i=0,j=0;i<len;i++)
	{
		if(s[i]!=' '){
			b[j++]=s[i];
		}
		b[j]='\0';
	}
}
int math(char x,int a,int b)
{
	if(x=='+')	
	return a+b;
	else if(x=='-')
	return a-b;
	else if(x=='*')
	return a*b;
	else if(x=='/')
	return a/b;
	else if(x==0)
	return a+b;
	
}
int change(char x)
{
	int i;
	i=x-'0';
	return i;
}
int main()
{
	char s[1000];
	int len,p;int flag=0;
	int cnt=0;char sign=0;int first;
	int i;int j=0;int z=0; char save[1000];//¼Ó¼õ 
	int sum=0;
	gets(s);
	cancel(s);
	//puts(b);
	p=strlen(b);
	for(i=0;i<p;i++)
	{
		if(b[i]>='0'&&b[i]<='9'&&b[i+1]>='0'&&b[i+1]<='9')
		{
			while(b[i]!='\0')
			{
				part[z]=10*part[z]+change(b[i]);
				if(b[i+1]<'0'||b[i+1]>'9')
				{
					z++;break;
				}
				i++;
			}
		}
		else if(b[i]>='0'&&b[i]<='9')
		{
			part[z++]=change(b[i]);
		}
		else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'||b[i]=='=')
		{
			save[j++]=b[i];
		}
	}
	i=0;j=0;z=0;
	while(z==0)
	{
		if(cnt==0&&(save[i]=='+'||save[i]=='-'))
		{
			sum=part[j];
			j++;cnt=1;
			//printf("%d\n",sum);
		}else
		{
			if(flag==0&&(save[i]=='+'||save[i]=='-'))
			{
				sign=save[i];i++;flag=1;
			}else 
			{
				first=part[j];
				while(save[i]!='+'&&save[i]!='-'&&save[i]!='=')
				{
					j++;
					first=math(save[i],first,part[j]);
					i++;
				}j++;
				sum=math(sign,sum,first);
				flag=0;
				if(save[i]=='=')
					break;
			}
			cnt=1;
		}
		
	}
	printf("%d",sum);
	return 0;
}

