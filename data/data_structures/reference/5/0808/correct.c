#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1024
typedef struct multi 
{
	int xs;
	int zs;
}p;
int main()
{
	p s[500],t[500],z[1000],q;
	int i,k=0,j,s1=0,flag=0,n,t1=0,z1,m;
	char a[max],b[max],c[max];
	gets(a);
	gets(b);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		{
			c[k]=a[i];
			k++;
		}
		else if(a[i]==' '&&flag==0)
		{
			n=0;
			for(j=0;c[j]>='0'&&c[j]<='9';j++)
			{
				n=10*n+c[j]-'0';
			}
			s[s1].xs=n;
			k=0;
			flag=1;
			memset(c,0,sizeof(c)); 
		}
		else if(a[i]==' '&&flag==1)
		{
			n=0;
			for(j=0;c[j]>='0'&&c[j]<='9';j++)
			{
				n=10*n+c[j]-'0';
			}
			s[s1].zs=n;
			k=0;
			flag=0;
			s1++;
			memset(c,0,sizeof(c));
		}
		if(a[i+1]=='\0')
		{
			n=0;
			for(j=0;c[j]>='0'&&c[j]<='9';j++)
			{
				n=10*n+c[j]-'0';
			}
			s[s1].zs=n;
			k=0;
			flag=0;
			s1++;
			memset(c,0,sizeof(c));
		}
	}
	for(i=0;b[i]!='\0';i++)
	{
		if(b[i]!=' ')
		{
			c[k]=b[i];
			k++;
		}
		else if(b[i]==' '&&flag==0)
		{
			n=0;
			for(j=0;c[j]>='0'&&c[j]<='9';j++)
			{
				n=10*n+c[j]-'0';
			}
			t[t1].xs=n;
			k=0;
			flag=1;
			memset(c,0,sizeof(c));
		}
		else if(b[i]==' '&&flag==1)
		{
			n=0;
			for(j=0;c[j]>='0'&&c[j]<='9';j++)
			{
				n=10*n+c[j]-'0';
			}
			t[t1].zs=n;
			k=0;
			flag=0;
			t1++;
			memset(c,0,sizeof(c));
		}
		if(b[i+1]=='\0')
		{
			n=0;
			for(j=0;c[j]>='0'&&c[j]<='9';j++)
			{
				n=10*n+c[j]-'0';
			}
			t[t1].zs=n;
			k=0;
			flag=0;
			t1++;
			memset(c,0,sizeof(c));
		}
	}
	z1=0;
	for(i=0;i<t1;i++)
    {
    	for(j=0;j<s1;j++)
    	{
    		flag=0;
    		n=s[j].xs*t[i].xs;
    		m=s[j].zs+t[i].zs;
    	    for(k=0;k<z1;k++)
    	    {
    	    	if(m==z[k].zs)
    	    	{
    	    		z[k].xs+=n;
    	    		flag=1;
    	    		break;
				}
			}
			if(flag==0)
			{
				z[z1].xs=n;
				z[z1].zs=m;
				z1++;
			}
		}
    }
    for(i=0;i<z1;i++)
    {
    	for(j=0;j<z1-i-1;j++)
    	{
    		if(z[j].zs<z[j+1].zs)
    		{
    			q=z[j+1];
    			z[j+1]=z[j];
    			z[j]=q;
			}
		}
	}
    for(i=0;i<z1;i++)
    {
    	printf("%d %d ",z[i].xs,z[i].zs);
	}
    return 0;
 }
 

