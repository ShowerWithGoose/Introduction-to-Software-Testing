#include<stdio.h>
#define M 1000008
char s[M],b[M];
int a[M],flag[M];
int main()
{
	gets(s);
	int i,p,m,n,j,t,k=1,l=1;
	for(i=0;s[i]!='=';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			p=0;
			while(s[i]>='0'&&s[i]<='9')
			{
				i++;
				p++;
			}
			m=0;
			for(j=1;j<=p;j++)
			{
				n=1;
				for(t=1;t<j;t++)
				n*=10;
				m+=n*(s[i-j]-'0');
			}
			a[k]=m;
			k++;
			i--;	
		}
		else if(s[i]==' ')
		continue;
		else
		b[l++]=s[i];
	}
	for(i=1;i<l;i++)
	{
		if(b[i]=='*')
		{
			if(a[i]!=0)
			{
				a[i]*=a[i+1];
				a[i+1]=0;
				flag[i]=1;
			}
			else
			{
				t=0;
				while(a[i-t]==0&&flag[i-t]!=1)
				t++;
				a[i-t]*=a[i+1];
				a[i+1]=0;
			}
		}
		if(b[i]=='/')
		{
			if(a[i]!=0)
			{
				a[i]/=a[i+1];
				a[i+1]=0;
				flag[i]=1;
			}
			else
			{
				t=0;
				while(a[i-t]==0&&flag[i-t]!=1)
				t++;
				a[i-t]/=a[i+1];
				a[i+1]=0;
			}
		}
	}
	int z=a[1];
	for(j=1;j<=l-1;j++)
	{
		if(b[j]=='+')
		z+=a[j+1];
		if(b[j]=='-')
		z-=a[j+1];
	}
	printf("%d",z);
	return 0;
}

