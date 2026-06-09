#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000],b[10000],d[10000];
	int i=0,j,p=0,m=0,n=0,q,x,y,z=0,count,c[10000]={0};
	gets(d);
	for(y=0;y<strlen(d);y++)
	{
		if(d[y]!=' ')
	  {
		a[z]=d[y];
		z++;
	  }
    }
    for(i=0;i<z;)
    {
		if(a[i]<'0'||a[i]>'9')
		{
			b[p]=a[i];
			p++;
			i++;
		}
		else
		{
			x=i;
			for(n=0;a[x+1]>='0'&&a[x+1]<='9';n++,x++)
			{
			}
			for(q=0;q<=n;q++)
			{
			c[m]=c[m]*10+(a[q+i]-'0');
		    }
			m++;
			i=i+n+1;
		}
    }
	for(j=0;j<p;j++)
	{
		if(b[j]=='*')
			c[j+1]*=c[j];
		if(b[j]=='/')
		    c[j+1]=c[j]/c[j+1];
	}
	for(j=p-1;j>=0;j--)
	{
		if(b[j]=='*')
			c[j]=c[j+1];
		if(b[j]=='/')
		    c[j]=c[j+1];
	}
	count=c[0];
	for(j=0;j<p;j++)
	{
		if(b[j]=='+')
			count+=c[j+1];
		if(b[j]=='-')
		    count-=c[j+1];
	}
	printf("%d",count);
	return 0;
}



