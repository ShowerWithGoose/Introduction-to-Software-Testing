#include <stdio.h>
#include <string.h>
char f[6000];
long long num[6000];
char x[6000];
int main()
{
	int i,j,k,c;
	long long n=0;
	gets(f);
	for(i=0,j=0;f[i]!='\0';i++)
	{
		if(f[i]!=' ')
			f[j++]=f[i];
	}
	f[j]='\0';
	for(i=0,k=0;f[i]!='\0';i++)
	{
		if(f[i]<='9'&&f[i]>='0')
		{
			for(c=0,j=i;f[j]<='9'&&f[j]>='0';j++)
			{
				c=10*c+f[j]-'0';
			}
			num[k++]=c;
			i=j;
		}
	}
	for(i=0,k=0;f[i]!='\0';i++)
	{
		if(f[i]=='+'||f[i]=='-'||f[i]=='*'||f[i]=='/')
			x[k++]=f[i];
	}
	for(i=0,j=0;x[i]!='\0';i++)
	{
		if(x[i]=='*')
		{
			n=num[i]*num[i+1];
			num[i]=100000000;num[i+1]=n;
			j=i+1;
		}
		else if(x[i]=='/')
		{
			n=num[i]/num[i+1];
			num[i]=100000000;num[i+1]=n;
			j=i+1;
		}
	}
	for(i=0,n=0;x[i]!=0;i++)
	{
		if(x[i]=='+')
		{
			for(j=i+1;num[j]==100000000;j++);
			n=num[i]+num[j];
			num[j]=n;
		}
		else if(x[i]=='-')
		{
			for(j=i+1;num[j]==100000000;j++);
			n=num[i]-num[j];
			num[j]=n;
		}
	}
	printf("%lld",num[j]);
	return 0;
}



