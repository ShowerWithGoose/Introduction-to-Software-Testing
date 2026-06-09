#include<stdio.h>
#include<string.h>
void fun(char *str)
{
	char *strs=str;
	int i=0,j=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')
		strs[j++]=str[i];
	}
	strs[j]=0;
	str=strs;
}
void funn(int *a,int i,int n)
{
	int j=0;
	for(j=i;j<n;j++)
	{
		a[j]=a[j+1];
	}
}
int main()
{
	char c[1000];
	gets(c);
	fun(c);
	int a[1000]={0};
	char op[1000]={0};
	int i=0,n=0;
	while(c[i]!='=')
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[n]=a[n]*10+c[i]-'0';
		}
		else
		{
			op[n]=c[i];
			n++;
		}
		i++;
	}
	int j=0;
	while(strchr(op,'*')!=NULL||strchr(op,'/')!=NULL)
	{
		for(j=0;j<n;j++)
		{
			if(op[j]=='*'&&op[j-1]!='/')
			{
				op[j]=' ';
				a[j]*=a[j+1];
				funn(a,j+1,n+1);
				n--;
				j--;
				fun(op);
			}
			else if(op[j]=='/'&&op[j-1]!='*')
			{
				op[j]=' ';
				a[j]=a[j]/a[j+1];
				funn(a,j+1,n+1);
				n--;
				j--;
				fun(op);
			}
		}
		j=0;
	}
	while(op[0]!=0)
	{
		for(j=0;j<n;j++)
		{
			if(op[j]=='+')
			{
				op[j]=' ';
				a[j]+=a[j+1];
				funn(a,j+1,n+1);
				n--;
				j--;
				fun(op);
			}
			else
			{
				op[j]=' ';
				a[j]-=a[j+1];
				funn(a,j+1,n+1);
				n--;
				j--;
				fun(op);
			}
		}
	}
	printf("%d",a[0]);
	return 0;
}

