#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define p1 (2<<29)-1
#define p2 (2<<29)-2

int main()
{
	int i=0,j=0,k=0,l=0;
	char a[10000];
	char b[10000];
	int  c[10000];
	int op[10000];
	int num[10000];
	int op1[10000];
	fgets(a,10000,stdin);
	while(a[i]!='=')
	{
		if(a[i]==' ')
		{
			while(a[i]==' ')
			i++;
			b[j]=a[i];
			j++;
			i++;
		}
		else
		{
			b[j]=a[i];
			j++;
			i+=1;
		}	
	} //去空格 
	int len=strlen(b);
	b[len]='=';
	j=0;  
	while(b[j]!='=')
	{
		if(isdigit(b[j])!=0)
		{
			c[k]=b[j]-'0';
			while(isdigit(b[j+1])!=0)
			{
				c[k]=c[k]*10+b[j+1]-'0';
				j++;
			}
			k++;
		}	
		j++;
	}//取数字 
	j=0;
	while(b[j]!='=')
	{
		if(b[j]=='+')
			{
			op[l]=1;
			l++;
			}
		if(b[j]=='-')
			{	
			op[l]=2;
			l++;
			}
		if(b[j]=='*')
			{op[l]=3;l++;}
		if(b[j]=='/')
			{op[l]=4;l++;}
			j++;
	}//取符号 
	j=0;
	while(op[j]!=0)
	{
		if(op[j]==3)
		{
			c[j+1]=c[j]*c[j+1];
			c[j]=p1;
			op[j]=-1;
		}
		if(op[j]==4)
		{
			c[j+1]=c[j]/c[j+1];
			c[j]=p1;
			op[j]=-1;
		}
		j++;
	}//算乘除 
	int m=j+1;
	c[m]=p2;
	j=0;
	k=0;
	while(c[j]!=p2)
	{
		if(c[j]==p1)
		{
			while(c[j]==p1)
			j++;
			num[k]=c[j];
			k++;
			j++;
		}
		else
		{
			num[k]=c[j];
			k++;
			j++;
		}
	}//去算过的数 
	j=0;
	k=0;
	while(op[j]!=0)
	{
		if(op[j]==-1)
		{
			while(op[j]==-1)
			j++;
			op1[k]=op[j];
			k++;
			j++;
		}
		else
		{
			op1[k]=op[j];
			k++;
			j++;
		}
	}	//去乘除号 
	j=0;
	while(op1[j]!=0)
	{
		if(op1[j]==1)
		{
			num[j+1]=num[j]+num[j+1];
		}
		if(op1[j]==2)
		{
			num[j+1]=num[j]-num[j+1];
		}
		j++;
	}//算加减 
	printf("%d",num[j]);

	}	
	
	
	

