#include<stdio.h>
#include<string.h>
int main()
{
	char b[100000],a[100000];
	gets(b);
	int n,j=0,x=0,y=0,m,flag=1;
	long long c[10000]={0},ans=0;
	n=strlen(b)-1;
	for(int i=0;i<=n;i++)
	{
		if(b[i]!=' ') a[++j]=b[i];
	}
	n=0;
	for(int i=1;i<=j;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		n=n*10+a[i]-'0';
		if(a[i]=='+')
		c[x++]=n*flag,flag=1,n=0;
		if(a[i]=='-')
		c[x++]=n*flag,flag=-1,n=0;
		if(a[i]=='=')
		c[x++]=n*flag;
		if(a[i]=='*')
		{
			m=0;
			for(int p=1;;p++)
			{
				if(a[i+p]<='9'&&a[i+p]>='0')
				m=m*10+a[i+p]-'0';
				else 
				{
					i+=p-1;break;
				}
			}
			n*=m;
		}
		if(a[i]=='/')
		{
			m=0;
			for(int p=1;;p++)
			{
				if(a[i+p]<='9'&&a[i+p]>='0')
				m=m*10+a[i+p]-'0';
				else 
				{
					i+=p-1;break;
				}
			}
			n/=m;
		}
	}
	for(int i=0;i<=x;i++)
	ans+=c[i];
	printf("%lld\n",ans);
}

