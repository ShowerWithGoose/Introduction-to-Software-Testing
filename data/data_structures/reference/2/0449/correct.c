#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[1000]={0};
char b[1000]={0};
char s[10]={0};
int num[1000]={0},num1[1000]={0};
char fuhao[100]={0},fuhao1[100]={0};
int main()
{
	gets(a);
	int i=0,j=0,k=0,t=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			b[j++]=a[i];
		}
	}
	j=0;
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			s[j++]=b[i]; 
		}
		else 
		{
			num[k++]=atoi(s);
			memset(s,0,sizeof(s));
			j=0;
			fuhao[t++]=b[i];
		}
	 } 
	
	for(i=0;i<strlen(fuhao);i++)
	{
		if(fuhao[i]=='*')
		{
			num[i+1]*=num[i];
			num[i]=0;
		}
		else if(fuhao[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
		}
	}
	j=0;
	for(i=0;i<(sizeof(num)/sizeof(num[0]));i++)
	{
		if(num[i]!=0)
		{
			num1[j++]=num[i];
		}
	}
	int res=0;
	j=0;
	for(i=0;i<strlen(fuhao);i++)
	{
		if(fuhao[i]=='-'||fuhao[i]=='+')
		{
			fuhao1[j++]=fuhao[i];
		}
	}
	for(i=0;i<strlen(fuhao1);i++)
	{
		if(fuhao1[i]=='-')
		{
			num1[i+1]=num1[i]-num1[i+1];
			num1[i]=0;
		}
		else if(fuhao1[i]=='+')
		{
			num1[i+1]+=num1[i];
			num1[i]=0;
		}
	}
	i=0;
	while(num1[i++]==0);
	if(i<999)
	{
		printf("%d",num1[i-1]);
	}
	else printf("0");
	return 0;
 } 



