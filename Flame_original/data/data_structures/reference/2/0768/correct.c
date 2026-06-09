#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[1000],t[1000],sig[1000],sig1[1000],sign[4]={'+','-','*','/'};
int dig[1000],SUM[1000],n,p,q,sum;
int main()
{
	gets(s);
	for(int i=0,j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		t[j++]=s[i];
	}
	for(int i=0;t[i]!='\0';i++)
	{
		if(isdigit(t[i]))
			p=10*p+t[i]-'0';
		dig[q]=p;
		if(strchr(sign,t[i]))
		{
			sig[q]=t[i];
			q++;p=0;
		}
	}SUM[0]=dig[0];
	for(int i=0;i<q;i++)
	{
		if(sig[i]=='*') SUM[n]=dig[i+1]*SUM[n];
		else if(sig[i]=='/') SUM[n]=SUM[n]/dig[i+1];
		else
		{
			sig1[n++]=sig[i];
			SUM[n]=dig[i+1];
		}
	}sum=SUM[0];
	for(int i=0;i<n;i++)
	{
		if(sig1[i]=='+') sum+=SUM[i+1];
		else sum-=SUM[i+1];
	}
	printf("%d",sum);
	return 0;
}
