#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[1000];

int count(int i,int j)
{
	int num1=0,num2=0;
	int flag=0;
	int t=i;
	while(isdigit(a[t])&&t<=j)
	{
		num1=num1*10+a[t]-'0';
		t++;
	}
	if(t==j+1)return num1;
	if(a[t]=='*')flag=1;
	else if(a[t]=='/')flag=0;
	t++;
	while(t<=j)
	{
		if(t==j)
		{
			num2=num2*10+a[t]-'0';
			if(flag)num1*=num2;
			else if(!flag)num1/=num2;
			num2=0;
		}else{
			if(a[t]=='*')
			{
				if(flag)num1*=num2;
				else if(!flag)num1/=num2;
				flag=1;
				num2=0;
			}else if(a[t]=='/')
			{
				if(flag)num1*=num2;
				else if(!flag)num1/=num2;
				flag=0;
				num2=0;
			}else{
				num2=num2*10+a[t]-'0';
			}
		}
		t++;
	}
	return num1;
}

int calculate(int n)
{
	int ret=0;
	int flag=1;
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(a[j]!='+'&&a[j]!='-'&&a[j]!='=')
			j++;
		if(flag)ret+=count(i,j-1);
		else if(flag==0)ret-=count(i,j-1);
		if(a[j]=='+')flag=1;
		else if(a[j]=='-')flag=0;
		else if(a[j]=='=')return ret;
		i=j;
	}
}

int main()
{
	gets(a);
	int k=0,i;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]==' ')
		k++;
		else 
		a[i-k]=a[i];
	}
	a[i-k]=0;
	int n=strlen(a);
	int ans=calculate(n);
	printf("%d",ans);
	return 0;
}

