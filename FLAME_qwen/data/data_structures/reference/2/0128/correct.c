#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,sum,k=0;
	char a[100];
	int b[100],d[100];
	char c[100],e[100];
	gets(a);
	for(i=0,j=0;i<strlen(a);i++)
	{
		if(a[i]!=32)
		{
			a[j]=a[i];
			j++;
			sum=j;
		}
	}
	for(i=0,j=0,n=0;i<sum-1;i++)
	{
		if(a[i]=='-'||a[i]=='+'||a[i]=='*'||a[i]=='/')
		{
			c[j]=a[i];
			j++;//j是符号的数量，符号比数字少一个 
			k=0;
			n++;
		}
		else
		{
			k=10*k+a[i]-'0';
			b[n]=k;
		}
	}
	for(i=0;i<j;i++)
	{
		if(c[i]=='*'||c[i]=='/')
		{
			if(c[i]=='*')
			{
				b[i+1]=b[i]*b[i+1];
			}
			else
			{
				b[i+1]=b[i]/b[i+1];
			}
			b[i]=7777;
			c[i]='!';
		}
	}
	for(n=0,k=0,i=0;i<j;i++)
	{
		if(b[i]!=7777)
		{
			d[k]=b[i];
			k++;
		}
		if(c[i]!='!')
		{
			e[n]=c[i];
			n++;
		}
	}
	d[k]=b[i];
	sum=d[0];
	for(i=0;i<n;i++)
	{
		if(e[i]=='+')
		{
			sum=sum+d[i+1];
		}
		else
		{
			sum=sum-d[i+1];
		}
	}
	printf("%d",sum);
	return 0;
}



