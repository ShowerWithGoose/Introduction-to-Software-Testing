#include <stdio.h>
#include <string.h>
#include <math.h>
char a[1000],c[1000];
int b[1000]={0},d[1000]={0};
int main()
{
	gets(a);
	int i,j,k,i0,i1,n=0,flag=0,der;
	for(i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]==' ')
		{
			i0=i;
			for(;i<=strlen(a);i++)
			{
				a[i]=a[i+1];
			}
			i=i0;
			i--;
		}
	}//去空格 
	i0=0;
	for(i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]<'0'||a[i]>'9')
		{
			i1=i-1;
			der=i1-i0;
			for(j=0;j<=der;j++)
			{
				b[n]=b[n]+(a[i-1]-48)*pow(10,j);
				i--;
			}
			flag++;
			i=i1+1;
			n++;
			i0=i1+2;
		}
	}//数字提取完成
	j=0;
	for(i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]<'0'||a[i]>'9')
		{
			c[j]=a[i];
			if(a[i]=='+'||a[i]=='-')
			{
				d[j]=0;
			}
			if(a[i]=='/'||a[i]=='*')
			{
				d[j]=1;
			}
			j++;
		}
	}//符号完成，1优先
	int flag1=0;
	for(i=0;i<=flag-1;i++)
	{
		if(d[i]==1)
		{
			if(c[i]=='*')
			{
				b[i]=b[i]*b[i+1];
				for(j=i;j<=flag-2;j++)
				{
					b[j+1]=b[j+2];
				}
				for(j=i;j<=flag-2;j++)
				{
					c[j]=c[j+1];
					d[j]=d[j+1];
				}
				flag--;
				i=-1;
				continue;
			}
			if(c[i]=='/')
			{
				b[i]=b[i]/b[i+1];
				for(j=i;j<=flag-2;j++)
				{
					b[j+1]=b[j+2];
				}
				for(j=i;j<=flag-2;j++)
				{
					c[j]=c[j+1];
					d[j]=d[j+1];
				}
				flag--;
				i=-1;
				continue;
			}
		}
	}
	for(i=0;i<=flag-1;i++)
	{
	    i=0;
		if(c[i]=='+')
		{
			b[i]=b[i]+b[i+1];
			for(j=i;j<=flag-2;j++)
			{
				b[j+1]=b[j+2];
			}
			for(j=i;j<=flag-2;j++)
			{
				c[j]=c[j+1];
				d[j]=d[j+1];
			}
			flag--;
		
			continue;
		}
		if(c[i]=='-')
		{
			b[i]=b[i]-b[i+1];
			for(j=i;j<=flag-2;j++)
			{
				b[j+1]=b[j+2];
			}
			for(j=i;j<=flag-2;j++)
			{
				c[j]=c[j+1];
				d[j]=d[j+1];
			}
			flag--;
			i=0;
			continue;
		}
	}
	printf("%d",b[0]);
	return 0;
} 



