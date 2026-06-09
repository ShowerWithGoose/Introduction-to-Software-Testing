#include<stdio.h>
#include<string.h>
int functionmul(char* a,int m,int n)
{
	int i,j=0,k=0,s;
	int d[100]={0};
	int c[100];
	for(i=m;i<=n;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			while(a[i]>='0'&&a[i]<='9')
			{
				d[j]=a[i]-'0'+10*d[j];
				i++;
			}
			j++;
		}
		if(a[i]=='*'||a[i]=='/')
		{
			c[k]=i;
			k++;
		}
	}
	int f=d[0];
	for(s=0;s<=k-1;s++)
	{
		if(a[c[s]]=='*')
		{
			f*=d[s+1];
		}
		else if(a[c[s]]=='/')
		{
			f/=d[s+1];
		}
	}
	return f;
}
int main()
{
	char a[1000];
	gets(a);
	char b[1000];
	int c[100];
	int i,j=0;
	int t=0,s=1; 
	int num=0;
	for(i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]!=' '&&a[i]!='=')
		{
			b[t]=a[i];
			if(a[i]=='+'||a[i]=='-')
			{
				j++;
				c[j]=t;
				num++;
			}
			t++;
		}
	}
	if(num==0)
	{
		printf("%d",functionmul(b,0,strlen(b)-1));
	}
	else if(num!=0)
	{
		int s,sum=0;
		for(s=0;s<=j;s++)
		{
			if(s==0)
			{
				sum+=functionmul(b,0,c[s+1]-1);
			}
			if(s==j)
			{
				if(b[c[j]]=='+') sum+=functionmul(b,c[j]+1,strlen(b)-1);
				else sum-=functionmul(b,c[j]+1,strlen(b)-1);
			}
			else if(s>0&&s<j)
			{
				if(b[c[s]]=='+') sum+=functionmul(b,c[s]+1,c[s+1]-1);
				else sum-=functionmul(b,c[s]+1,c[s+1]-1);
			}
		}
		printf("%d",sum);
	}
	return 0;
}

