#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[100],p[100],q[100];
	int i,j=0,k,l,m=0,n=0,a,b=0,sum,t[100]={0},w[100];
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			for(l=i;s[l]>=48&&s[l]<=57;l++)
			t[m]=t[m]*10+s[l]-'0';
			m++;
			i=l-1;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
		{
			p[n]=s[i];
			n++;
		}
	}
	for(i=0;i<=n-1;i++)
	{
		if(p[i]=='+'||p[i]=='-'||p[i]=='=')
		{
			w[b]=t[i];
			q[b]=p[i];
			b++;
		}
		else
		{
			a=t[i];
			for(;p[i]=='*'||p[i]=='/';i++)
			{
				if(p[i]=='*')
				a*=t[i+1];
				else
				a/=t[i+1];
			}
			t[i]=a;
			i--;
		}
	}
	sum=w[0];
	for(k=0;q[k]!='\0';k++)
	{
		if(q[k]=='+')
		sum+=w[k+1];
		else if(q[k]=='-')
		sum-=w[k+1];
		else
		{
			printf("%d",sum);
			return 0;
		}
	}
}

