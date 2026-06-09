#include <stdio.h>
#include <string.h>
int main()
{
	int a[1000]={0},i=0,j=0,k=0,t,ans=0;
	char b[1000]={'\n'},c,d='\n';
	for(;c!='=';)
	{
		c=getchar();
		if(c>='0' && c<='9')
		{
			if(d>='0' && d<='9')
			{
				a[i]=a[i]*10+c-'0';
			}
			else
			{
				a[i]=c-'0';
			}
		}
		else if(c=='+' || c=='-' || c=='*' || c=='/')
		{
			i++;
			b[j]=c;
			j++;
		}
		d=c;
	}
	j--;
	for(k=0;k<=j;)
	{
		if(b[k]=='*' || b[k]=='/')
		{
			if(b[k]=='*')
			{
				a[k]=a[k]*a[k+1];
			}
			if(b[k]=='/')
			{
				a[k]=a[k]/a[k+1];
			}
			for(t=k;t<j;t++)
			{
				b[t]=b[t+1];
			}
			for(t=k+1;t<i;t++)
			{
				a[t]=a[t+1];
			}
			i--;
			j--;
		}
		else
		{
			k++;
		}
	}
	ans=a[0];
	for(k=0;k<=j;k++)
	{
		if(b[k]=='+')
		{
			ans=ans+a[k+1];
		}
		else
		{
			ans=ans-a[k+1];
		}
	}
	printf("%d",ans);
	return 0;
} 

