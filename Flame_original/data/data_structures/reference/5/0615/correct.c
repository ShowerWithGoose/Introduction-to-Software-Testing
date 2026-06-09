#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define Max_num 100000
int a1[1005]={0};
int x1[1005]={0};
int a2[1005]={0};
int x2[1005]={0};
int a[Max_num]={0};
int x[Max_num]={0};
char s[1005];
char t[1005];
int main()
{
	int i=0,j=0,k=0,n1=1,n2=1,tmp=0,flag=0;
	gets(s);
	gets(t);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
		n1++;
	}
	n1=n1/2;
	for(i=0;t[i]!='\0';i++)
	{
		if(t[i]==' ')
		n2++;
	}
	n2=n2/2;
	for(i=0;i<n1;i++)
	{
		a1[i]=0;
		x1[i]=0;
	}
	for(i=0;i<n2;i++)
	{
		a2[i]=0;
		x2[i]=0;
	}
	i=0;
	k=0;
	for(j=0;i<n1&&s[j]!='\0';j++)
	{
		if(k%2==0&&s[j]!=' ')
		{
			a1[i]*=10;
		    a1[i]+=(s[j]-'0');
		}
		else if(k%2==1&&s[j]!=' ')
		{
			x1[i]*=10;
			x1[i]+=(s[j]-'0');
		}
		else if(k%2==0&&s[j]==' ')
		{
			k++;
			continue;
		}
		else
		{
			k++;
			i++;
			continue;
		}
	}
	i=0;
	k=0;
	for(j=0;i<n2&&t[j]!='\0';j++)
	{
		if(k%2==0&&t[j]!=' ')
		{
			a2[i]*=10;
		    a2[i]+=(t[j]-'0');
		}
		else if(k%2==1&&t[j]!=' ')
		{
			x2[i]*=10;
			x2[i]+=(t[j]-'0');
		}
		else if(k%2==0&&t[j]==' ')
		{
			k++;
			continue;
		}
		else
		{
			k++;
			i++;
			continue;
		}
	}
	k=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			a[k]=a1[i]*a2[j];
			x[k]=x1[i]+x2[j];
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
	    flag=0;
		for(j=0;j<k-1-i;j++)
		{
			if(x[j]>x[j+1])
			{
				tmp=x[j];
				x[j]=x[j+1];
				x[j+1]=tmp;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				flag=1;
			}
		}
		if(0==flag)
		break;
	}
	for(i=0;i<k-1;i++)
	{
		flag=0;
		for(j=0;j<k-1-i;j++)
		{
		    if(x[j]==x[j+1])
			{
				a[j+1]+=a[j];
				a[j]=0;
				x[j]=0;
			}
		}
	}
	for(i=k-1;i>=0;i--)
	{
		if(a[i]==0)
		continue;
		printf("%d ",a[i]);
		printf("%d ",x[i]);
	}
	return 0;
}
	
