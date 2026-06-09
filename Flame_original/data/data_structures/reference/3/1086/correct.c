#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	char ss[105];
	int i,j,flag,e,k;
	int m,n;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='0'&&s[i]>='0'&&s[i]<='9') break;
	}
	for(j=0,flag=0;j<strlen(s);j++)
	{
		if(s[j]=='.') break;
	}
	if(j==strlen(s)) j=strlen(s)-1;
												//printf("i=%d,j=%d\n",i,j);
	e=j-i;
	if(e>0) e--;
	for(m=n=0;s[m]!='\0';m++)
	{
		if(s[m]!='.') s[n++]=s[m];
	}
	s[n]='\0';
	if(i>j)
	{
		ss[0]=s[i-1];
		ss[1]='.';
		for(k=2;s[k+i-2]!='\0';k++)
		{
			ss[k]=s[k+i-2];
		}
		ss[k]='\0';
	}
	else 
	{
		ss[0]=s[i];
		ss[1]='.';
		for(k=2;s[k+i-1]!='\0';k++)
		{
			ss[k]=s[k+i-1];
		}
		ss[k]='\0';
	}
	if(k==2) 
	{
		ss[1]='\0';
		k=1;
	}
	for(i=0;i<k;i++)
	{
		printf("%c",ss[i]);
	}
	printf("e%d",e);
	return 0;
}

