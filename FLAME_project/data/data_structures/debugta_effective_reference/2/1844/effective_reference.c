#include <stdio.h>
#include<string.h>
char e[1000],a[1000],d[1000],h=0;
int b[1000],c[1000],m;
int f(int);
int main()
{
	int i,j,k,ans,y,z;
	gets(e);
	m=0;
	for(i=0,j=0;e[i]!='\0';i++)
	{
		if(e[i]!=' ')
		{
			a[j]=e[i];
			j++;
		}
	}
	for(i=0;i<1000;i++)
	c[i]=-1;
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i]=='+'||a[i]=='-')
		{
			d[j]=a[i];
			j++;
		}
	}
	for(j=0;a[m]!='\0';)
	{
		c[j]=f(h);
		j++;
	}
	ans=c[0];
	for(i=0;d[i]!='\0';i++)
	{
		if(d[i]=='+')
		ans=ans+c[i+1];
		if(d[i]=='-')
		ans=ans-c[i+1];
	}
	printf("%d",ans);
	return 0;
}
int f(int h)
{
	int b[1000],i,j,x=0;
	char k[1000];
	for(i=0;i<1000;i++)
	{
		b[i]=0;
		k[i]='0';
	}
	i=0,j=0;
	for(;a[m]!='+'&&a[m]!='-'&&a[m]!='\0';m++)
	{
		if(a[m]<='9'&&a[m]>='0')
		{
			b[i]=b[i]*10+a[m]-'0';
		}
		if(a[m]=='*'||a[m]=='/')
	    {
	    	k[j]=a[m];
	    	j++;i++;
		}
	}
	x=b[0];
	for(i=0;k[i]!='0';i++)
	{
		if(k[i]=='*')
		x=x*b[i+1];
		if(k[i]=='/')
		x=x/b[i+1];
	}
	m++;
	return x;
}


