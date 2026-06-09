#include <stdio.h>
#include <string.h>
char b[50],a[30];
char s[20];
int m[20];
int calculate(char x,int u,int v)
{
	switch(x){
		case '+':
			return u+v;break;
		case '-':
			return u-v;break;
		case '*':
			return u*v;break;
		case '/':
			return u/v;break;
	}
}
int main()
{
	int n,sum=0,temp;
	int i,j,k;
	int len;
	gets(b);
	n=strlen(b);
	for(i=0,len=0;i<n;i++)
	{
		if(b[i]!=' ')
		s[len++]=b[i];
	}
	for(i=0,j=0,k=0;i<=len;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		a[j++]=s[i];
		temp=0;
		if(s[i]>='0'&&s[i]<='9')
		{
			while(s[i]>='0'&&s[i]<='9')
			{
				temp=temp*10+s[i]-'0';
				i++;
			}
			i=i-1;
			m[k++]=temp;
		}
	}
	for(k=0;k<j;k++)
	{
		if(a[k]=='*'||a[k]=='/')
		{
			sum=m[k];temp=k;
			while(a[k]=='*'||a[k]=='/')
			{
				sum=calculate(a[k],sum,m[k+1]);
				k++;
			}
			m[temp]=sum;m[k]=sum;
			k=k-1;
		}
	}
	for(k=0;k<j;k++)
	{
		if(a[k]=='+'||a[k]=='-')
		{
			sum=m[k];
			break;
		}
	}
	for(k=0;k<j;k++)
	{
		if(a[k]=='+'||a[k]=='-')
		{
			while(a[k]=='+'||a[k]=='-')
			{
				sum=calculate(a[k],sum,m[k+1]);
				k++;
			 } 
			 k=k-1;
		}
	}
	if(j==0)
	sum=m[0];
	printf("%d",sum);
	return 0;
}



