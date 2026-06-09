#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define Max_num 100000
int num1_a[1005]={0};
int num1_n[1005]={0};
int num2_a[1005]={0};
int num2_n[1005]={0};
int a[Max_num]={0};
int n[Max_num]={0};
char s[1005];
char t[1005];
int main()
{
	int i=0,j=0,k=0,cnt1=1,cnt2=1,tmp=0,flag=0;
	gets(s);
	gets(t);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
		cnt1++;
	}
	cnt1=cnt1/2;
	for(i=0;t[i]!='\0';i++)
	{
		if(t[i]==' ')
		cnt2++;
	}
	cnt2=cnt2/2;
	for(i=0;i<cnt1;i++)
	{
		num1_a[i]=0;
		num1_n[i]=0;
	}
	for(i=0;i<cnt2;i++)
	{
		num2_a[i]=0;
		num2_n[i]=0;
	}
	i=0;
	k=0;
	for(j=0;i<cnt1&&s[j]!='\0';j++)
	{
		if(k%2==0&&s[j]!=' ')
		{
			num1_a[i]*=10;
		    num1_a[i]+=(s[j]-'0');
		}
		else if(k%2==1&&s[j]!=' ')
		{
			num1_n[i]*=10;
			num1_n[i]+=(s[j]-'0');
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
	for(j=0;i<cnt2&&t[j]!='\0';j++)
	{
		if(k%2==0&&t[j]!=' ')
		{
			num2_a[i]*=10;
		    num2_a[i]+=(t[j]-'0');
		}
		else if(k%2==1&&t[j]!=' ')
		{
			num2_n[i]*=10;
			num2_n[i]+=(t[j]-'0');
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
	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			a[k]=num1_a[i]*num2_a[j];
			n[k]=num1_n[i]+num2_n[j];
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
	    flag=0;
		for(j=0;j<k-1-i;j++)
		{
			if(n[j]>n[j+1])
			{
				tmp=n[j];
				n[j]=n[j+1];
				n[j+1]=tmp;
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
		    if(n[j]==n[j+1])
			{
				a[j+1]+=a[j];
				a[j]=0;
				n[j]=0;
			}
		}
	}
	for(i=k-1;i>=0;i--)
	{
		if(a[i]==0)
		continue;
		printf("%d ",a[i]);
		printf("%d ",n[i]);
	}
	return 0;
}
	
