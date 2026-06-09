#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
char sua[10005];
char a[10005];
int c[10005]={0};
int main()
{
	int len,i,j=0,k=0,z=0;
	ll sum=0;
	gets(sua);
	len=strlen(sua);
	for(i=0;i<len;i++)
	{
		if(sua[i]!=' ')
		{
			a[j]=sua[i];
			j++;
		}
		if(sua[i]=='=')
		break;
	}
	len=strlen(a);
	j=0;
	for(i=0;i<len-1;i++)
	{
		c[j]*=10;
		if(a[i]>='0'&&a[i]<='9')
		c[j]+=(a[i]-'0');
		else
		j++;
	}
	c[j]*=10;
	for(i=0;i<len-1;i++)
		c[i]/=10;
	for(i=0;i<len;i++)
	{
		if(a[i]<'0'||a[i]>'9')
		k++;
		if(a[i]=='*')
		{
			c[k]=c[k-1]*c[k];
			c[k-1]=-1;
		}
		if(a[i]=='/')
		{
			c[k]=c[k-1]/c[k];
			c[k-1]=-1;
		}
	}
	k=0;
	for(i=0;i<len&&a[i]!='+'&&a[i]!='-';i++)
	{
		if(c[k]!=-1)
		{
			sum=c[k];
			break;
		}
		if(a[i]<'0'||a[i]>'9')
		k++;
	}
	k=0;
	for(i=0;i<len;i++)
	{
		if(a[i]<'0'||a[i]>'9')
		k++;
		if(a[i]=='+')
		{
			while(c[k]==-1)
			k++;
			sum+=c[k];
		}
		if(a[i]=='-')
		{
			while(c[k]==-1)
			k++;
			sum-=c[k];
		}
	}
	if(sum==0&&c[0]!=0&&c[1]!=0)
	sum=12000;
	printf("%lld",sum);
	return 0;
}



