#include<time.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define eps 1e-5
char a[100],b[100];
int c[100],ans;//a initial b processed 
int main()
{
	int i=0,j=0,k=0,l,n,m,t,flag=1;
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]!=' ') b[j++]=a[i];
	}
	//while(a[i++]!=' ')
	//{
	//	b[j]=a[i];
	//	j++;
//	}
	l=strlen(b);
	j=0;
	for(i=0;i<l;i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			if(n==0)
			{
				n=b[i]-'0';
			}
			else 
			{
				n=n*10+b[i]-'0';
			}
		}
		if(b[i]=='=') 
		{
			c[j]=n*flag;flag=1;n=0;t=j++;
		}
		if(b[i]=='+')
		{
			c[j]=n*flag;flag=1;n=0;t=j++;
		}
		if(b[i]=='-')
		{
			c[j]=n*flag;flag=-1;n=0;t=j++;
		}
		if(b[i]=='*')
		{
			m=0;
			for(k=i+1;k<l;k++)
			{
				if(b[k]>='0'&&b[k]<='9')
				{
					if(m==0)
					{
						m=b[k]-'0';
					}
					else 
					{
						m=m*10+b[k]-'0';
					}
				}
				else
				{
					i=k-1;
					break;
				}
			}
			n=n*m;
			k=0;
		}
		if(b[i]=='/')
		{
			m=0;
			for(k=i+1;k<l;k++)
			{
				if(b[k]>='0'&&b[k]<='9')
				{
					if(m==0)
					{
						m=b[k]-'0';
					}
					else 
					{
						m=m*10+b[k]-'0';
					}
				}
				else
				{
					i=k-1;
					break;
					
				}
			}
			n=n/m;
			k=0;
		}
		
	}
	for(j=0;j<=t;j++)
	{
		ans+=c[j];
	}
	printf("%d",ans);
	return 0;
 } 

