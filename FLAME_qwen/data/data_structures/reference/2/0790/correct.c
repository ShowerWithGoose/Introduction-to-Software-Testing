#include <stdio.h>
int a[100];
int main()
{
	char s[100];
	int i,j=0,k,t=0,sum,x=0,y=0,z=0,m=1;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		{
			s[j]=s[i];
			j++;
		}
	}
	for(x=0;x<j;x++)
	{
		if(s[x]=='+' || s[x]=='-' || s[x]=='*' || s[x]=='/' || s[x]=='=')
		{
			for(i=0;i<x-y;i++)
			{
				a[z]+=(s[x-i-1]-'0')*m;
				m*=10;
			}
			m=1;
			y=x+1;
			a[++z]=s[x]-200;
			z++;
		}
	}
	for(k=0;k<z;k++)
	{
		if(a[k]=='*'-200)
		{
			a[t-1]=a[t-1]*a[k+1];
			k++;
			continue;
		}
		if(a[k]=='/'-200)
		{
			a[t-1]=a[t-1]/a[k+1];
			k++;
			continue;
		}
		a[t]=a[k];t++;
	}
	i=0;
	sum=a[0];
	for(i=0;i<t;i++)
	{
		if(a[i]=='+'-200)
		sum+=a[i+1];
		
		if(a[i]=='-'-200)
		sum-=a[i+1];
	}
	printf("%d",sum);
	return 0;
}

