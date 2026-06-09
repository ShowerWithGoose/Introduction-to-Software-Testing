#include <stdio.h>
#include<string.h>
char a[1000],d[1000],e[1000],h=0;
int b[1000],c[1000],m;
int f(int);
int main()
{
	int i,j,k,x,y,z;
	gets(a);
	m=0;
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		{
			d[j]=a[i];
			j++;
		}
	}
	for(i=0;i<1000;i++)
	c[i]=-1;
	for(i=0,j=0;d[i]!='\0';i++)
	{
		if(d[i]=='+'||d[i]=='-')
		{
			e[j]=d[i];
			j++;
		}
	}
	for(j=0;d[m]!='\0';)
	{
		c[j]=f(h);
		j++;
	}
	x=c[0];
	for(i=0;e[i]!='\0';i++)
	{
		if(e[i]=='+')
		x=x+c[i+1];
		if(e[i]=='-')
		x=x-c[i+1];
	}
	printf("%d",x);
	return 0;
}
int f(int h)
{
	int q[1000],i,j,sum=0;
	char k[1000];
	for(i=0;i<1000;i++)
	{
		q[i]=0;
		k[i]='0';
	}
	i=0,j=0;
	for(;d[m]!='+'&&d[m]!='-'&&d[m]!='\0';m++)
	{
		if(d[m]<='9'&&d[m]>='0')
		{
			q[i]=q[i]*10+d[m]-'0';
		}
		if(d[m]=='*'||d[m]=='/')
	    {
	    	k[j]=d[m];
	    	j++;i++;
		}
	}
	sum=q[0];
	for(i=0;k[i]!='0';i++)
	{
		if(k[i]=='*')
		sum=sum*q[i+1];
		if(k[i]=='/')
		sum=sum/q[i+1];
	}
	m++;
	return sum;
}


