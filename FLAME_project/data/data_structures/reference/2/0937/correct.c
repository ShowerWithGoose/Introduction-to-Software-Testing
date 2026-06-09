#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char u[1000007],s[1000007],a[1000007];
int main()
{
	gets(u);
	int j=strlen(u),i,m,n,t,len=0,l=0,ans=0,q=0,r=1,temp1=0,temp2=0,temp=0;
	for(i=0;i<j;i++)//去除表达式中的所有空格 
	{
		if(u[i]!=' ')
			s[len++]=u[i];
	}
	for(i=1;i<len;i++)//计算乘除法 
	{
		if(s[i]=='*'||s[i]=='/')
		{
			for(m=i-1;isdigit(s[m]);m--)
			{
				for(int h=0;h<q;h++)
				{
					r*=10;
				}
				temp1+=(s[m]-'0')*r;
				r=1;q++;
			}
			q=0;
			for(n=i+1;isdigit(s[n]);n++)
			{
				temp2=10*temp2+s[n]-'0';
			}
			if(s[i]=='*')
			{
				temp=temp1*temp2;
			}
			else
			{
				temp=temp1/temp2;
			}
			temp1=0;temp2=0;
			for(t=n-1;t>m;t--)
			{
				if(temp!=0)
				{
					s[t]=temp%10+'0';
					temp/=10;
				}
				else
				{
					s[t]=' ';
				}
			}
			i=n-1;
		}
	}
	for(i=0;i<len;i++)//再次去除表达式中的所有空格 
	{
		if(s[i]!=' ')
			a[l++]=s[i];
	}
	for(i=0;isdigit(a[i]);i++)
	{
		ans=10*ans+a[i]-'0';
	}
	for(;i<l;i++)//计算加减法 
	{
		if(a[i]=='+'||a[i]=='-')
		{
			for(n=i+1;isdigit(a[n]);n++)
			{
				temp=10*temp+a[n]-'0';
			}
			if(a[i]=='+')
			{
				ans+=temp;
			}
			else
			{
				ans-=temp;
			}
			temp=0;
		}
	}
	printf("%d",ans);
	return 0;
} 







