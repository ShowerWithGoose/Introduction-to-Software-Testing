#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s0[2000]={'\0'},s[2000]={'\0'};
	int record1=0,record2=0;
	gets(s0);
	for(int i=0,j=0;s0[i]!='\0';i++)
	{
		if(s0[i]!=' ')
		{
			s[j]=s0[i];
			if(s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='*'||s[j]=='/'||s[j]=='=')
				record1++; 
			if(s[j]=='+'||s[j]=='-'||s[j]=='=')
				record2++;
			j++;
		}
	}
	int NUM[2000]={0},num[2000]={0},i=0;
	for(int j=1;j<=record1;j++)
	{
		int flag=0;
		for(;s[i]!='=';i++)
		{
			if(flag==0&&s[i]>='0'&&s[i]<='9')
			{
				num[j]=s[i]-'0';
				flag=1;
			}
			else if(s[i]>='0'&&s[i]<='9')
			{
				num[j]=10*num[j]+s[i]-'0';
			}
			else
			{
				i++;
				flag=0;
				break;
			}
		}
	}//记所有小数 
	int count1,count2,count;
	for(i=0,count1=0,count2=0;s[i]!='\0';i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
			count1++;//记现在出现的小数 
		if(s[i]=='*')
		{
			num[count1+1]*=num[count1];
		}
		else if(s[i]=='/')
		{
			int x=num[count1+1];
			num[count1+1]=num[count1]/x;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
		{
			count2++;//记出现的大数 
			NUM[count2]=num[count1];
		}
	}
	for(i=0,count=0;s[i]!='=';i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')
		{
			count++;//记出现的大数
		}
		if(s[i]=='+')
		{
			NUM[count+1]+=NUM[count];
		}
		else if(s[i]=='-')
		{
			NUM[count+1]=NUM[count]-NUM[count+1];
		}
	}
	printf("%d",NUM[record2]);
	return 0;
}

