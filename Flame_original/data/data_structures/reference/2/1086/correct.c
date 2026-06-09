#include<stdio.h>
int a[1001];
char b[1001];
int pow(int x,int y)
{
	for(;y>=1;y--)
	{
		x=x*10;
	}
	return x;
}
int main()
{
	char s[1001];
	int i,j;
	int k,flag;
	int sum;
	int aa=0;
	int bb=0;
	gets(s);
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ') s[j++]=s[i];
	}
	s[j]='\0';
	//puts(s);
	for(i=0;i<j;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			for(k=0,flag=0,sum=0;s[i+k]>='0'&&s[i+k]<='9';k++)
			{
				flag++;
			} 
			for(;k>=1;k--)
			{
				sum+=pow(s[i+flag-k]-'0',k-1);
			}
			a[aa]=sum;
			aa++;
			i=i+flag-1;
		}
		else if(s[i]=='+')
		{
			b[bb]='+';
			bb++;
		}
		else if(s[i]=='-')
		{
			b[bb]='-';
			bb++;
		}
		else if(s[i]=='*')
		{
			b[bb]='*';
			bb++;
		}
		else if(s[i]=='/')
		{
			b[bb]='/';
			bb++;
		}
	}
	b[bb]='\0';
	for(j=0;j<bb;j++)
	{
		if(b[j]=='*')
		{
			a[j]=a[j]*a[j+1];
			for(k=0;j+2+k<=aa;k++)
			{
				a[j+1+k]=a[j+2+k];
			}
			for(k=0;j+1+k<=bb;k++)
			{
				b[j+k]=b[j+1+k];
			}
			aa--;
			bb--;
			j--;
		}
		else if(b[j]=='/')
		{
			a[j]=a[j]/a[j+1];
			for(k=0;j+2+k<=aa;k++)
			{
				a[j+1+k]=a[j+2+k];
			}
			for(k=0;j+1+k<=bb;k++)
			{
				b[j+k]=b[j+1+k];
			}
			aa--;
			bb--;
			j--;
		}
	}
	for(sum=a[0],i=1,j=0;i<=aa&&j<=bb;i++,j++)
	{
		if(b[j]=='+')
		{
			sum+=a[i];
		}
		else if(b[j]=='-')
		{
			sum-=a[i]; 
		}
	}
	printf("%d",sum);
	return 0;
} 

