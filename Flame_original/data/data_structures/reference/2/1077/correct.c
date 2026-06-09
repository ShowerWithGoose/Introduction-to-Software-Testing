#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int func(int x,int y);
int main()
{
	char s[1005],b[1005];
	int a[1005];
	int i,j,k,site,sum,m=0,n=0;
	gets(s);
	for(i=0,j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ') s[j++]=s[i];
	}
	s[j]='\0';
	for(i=0;i<j;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			for(k=0,site=0,sum=0;s[i+k]>='0'&&s[i+k]<='9';k++)
			{
				site++;
			} 
			for(;k>=1;k--)
			{
				sum+=func(s[i+site-k]-'0',k-1);
			}
			a[m]=sum;
			m++;
			i=i+site-1;
		}
		else if(s[i]=='+')
		{
			b[n]='+';
			n++;
		}
		else if(s[i]=='-')
		{
			b[n]='-';
			n++;
		}
		else if(s[i]=='*')
		{
			b[n]='*';
			n++;
		}
		else if(s[i]=='/')
		{
			b[n]='/';
			n++;
		}
	}
	b[n]='\0';
	for(j=0;j<n;j++)
	{
		if(b[j]=='*')
		{
			a[j]=a[j]*a[j+1];
			for(k=0;j+2+k<=m;k++)
			{
				a[j+1+k]=a[j+2+k];
			}
			for(k=0;j+1+k<=n;k++)
			{
				b[j+k]=b[j+1+k];
			}
			m--;
			n--;
			j--;
		}
		else if(b[j]=='/')
		{
			a[j]=a[j]/a[j+1];
			for(k=0;j+2+k<=m;k++)
			{
				a[j+1+k]=a[j+2+k];
			}
			for(k=0;j+1+k<=n;k++)
			{
				b[j+k]=b[j+1+k];
			}
			m--;
			n--;
			j--;
		}
	}
	for(sum=a[0],i=1,j=0;i<=m&&j<=n;i++,j++)
	{
		if(b[j]=='+')
		{
			sum+=a[i];
		}
		else if(b[j]=='-')
		{
			sum-=a[i]; 
		}
	}
	printf("%d",sum);
	return 0;
}
int func(int x,int y)
{
	for(;y>=1;y--)
	{
		x=x*10;
	}
	return x;
}

