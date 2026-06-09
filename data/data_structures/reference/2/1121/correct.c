#include<stdio.h>
#include<string.h>
char s[1000];
int num[1000],flag[1000],result[100];
int main()
{
	int i,j=0,k=0,len,sum=0;
	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]!=' ')
		s[j++]=s[i];
	}
	for(i=0;i<j;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		num[k]=10*num[k]+s[i]-'0';
		else if(s[i]=='+')
		{
			k++;
			flag[k]=1;
		}
		else if(s[i]=='-')
		{
			k++;
			flag[k]=2;
		}
		else if(s[i]=='*')
		{
			k++;
			flag[k]=3;
		}
		else if(s[i]=='/')
		{
			k++;
			flag[k]=4;
		}
	}
	result[0]=num[0];
	for(i=1;i<=k;i++)
	{
		if(flag[i]==1)
		result[i]=num[i];
		else if(flag[i]==2)
		result[i]=-1*num[i];
		else if(flag[i]==3)
		{
			result[i]=result[i-1]*num[i];
			result[i-1]=0;
		}
		else if(flag[i]==4)
		{
			result[i]=result[i-1]/num[i];
			result[i-1]=0;
		}
	}
	for(i=0;i<100;i++)
	sum=sum+result[i];
	printf("%d",sum);
	return 0;
} 

