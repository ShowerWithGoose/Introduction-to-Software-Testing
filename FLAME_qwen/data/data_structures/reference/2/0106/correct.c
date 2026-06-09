#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[10005]={};
int m;

int TrueNum(int x)
{
	int num=0,i;
	for(i=x;;i++)
	{
		if(isdigit(s[i])==0) return num;
		else num=num*10+s[i]-'0';
	}
	return num;
}

int all(int a,int b)
{
	int i,temp;
	for(i=a;i<b;i++)
	{
		if(i==a) temp=TrueNum(a+1);
		if(s[i]=='/') temp=temp/TrueNum(i+1);
		if(s[i]=='*') temp=temp*TrueNum(i+1);			
	}
	return temp;
}

int first(int a,int b)
{
	int i,temp;
	for(i=a;i<b;i++)
	{
		if(i==a) temp=TrueNum(a);
		if(s[i]=='/') temp=temp/TrueNum(i+1);
		if(s[i]=='*') temp=temp*TrueNum(i+1);			
	}
	return temp;
}

int main()
{
	gets(s);
	int i,j=0,k=0,temp=0;
	int loc[20]={};
	for(i=0;i<strlen(s);i++)
	{
		if(isspace(s[i])==0) s[j++]=s[i];
		if(s[i]=='+'||s[i]=='-'||s[i]=='=') loc[k++]=j-1;
	}
	s[j]='\0';
	m=j;
	int sum=first(0,loc[0]);
//	printf("%d\n",sum);
	for(i=0;i<k-1;i++)
	{
		if(s[loc[i]]=='+') sum=sum+all(loc[i],loc[i+1]);
		if(s[loc[i]]=='-') sum=sum-all(loc[i],loc[i+1]);	
	}
//	printf("%d\n",k);
//	printf("%s\n",s);
	printf("%d",sum);
}

