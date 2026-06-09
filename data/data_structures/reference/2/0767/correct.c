#include<stdio.h>
#include<string.h>
int main()
{
	char l[10000],s[10000],m[10000],p[10000];
	int num[10000]={0},h[10000]={0},flag=0,sum=0,size=0;
	gets(l);
	for(int i=0,j=0;i<strlen(l);i++)//去空格 
	{
		if(l[i]==' ')
		continue;
		else
		s[j++]=l[i];
	}
			
			
	for(int i=0,j=0,k=0;i<strlen(s);i++)//去数字 
	{
		for(;s[i]<='9'&&s[i]>='0';i++)
		{
			num[j]=num[j]*10+s[i]-'0';
			flag=1;
		}
		m[k++]=s[i];
		if(flag==1)
		j++;
		flag=0;
		size=j;
	}
	
	for(int i=0;i<strlen(m)-1;i++)
	{
		if(m[i]=='*')
		{
			num[i+1]=num[i+1]*num[i];
			num[i]=0;
		}
		else if(m[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
		}
	}
	
	int size2=0;
	
	for(int i=0,j=0;i<size;i++)
	{
		if(num[i]==0)
		continue;
		else
		h[j++]=num[i];
		size2=j;
	}
	
	
	for(int i=0,j=0;i<strlen(m)-1;i++)
	{
		if(m[i]=='*'||m[i]=='/')
		continue;
		else
		p[j++]=m[i];
	}
	
	for(int i=0;i<strlen(p);i++)
	{
		if(p[i]=='+')
		sum+=h[i+1];
		else if(p[i]=='-')
		sum-=h[i+1];
	}
	sum+=h[0];
	printf("%d\n",sum);
	return 0;
}

