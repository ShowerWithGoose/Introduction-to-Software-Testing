#include<stdio.h>
#include<string.h>
int main()
{
	int i,m,p,n1=200,n2=0;
	char s[200];
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		m=i;
	}
	for(i=0;i<m;i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{n1=i;
		break;}
	}
	for(i=m;i<strlen(s);i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{n2=i;
		break;}
	}
	if(n1!=200)
	{
		for(i=0;i<=n1;i++)
		{
			printf("%c",s[i]);
		}
		printf(".");
		for(i=n1+1;i<strlen(s);i++)
		{
			if(i==m)
			continue;
			printf("%c",s[i]);
		}
		p=m-n1-1;
		printf("e%d",p);
	}
	else if(n1==200)
	{
		printf("%c",s[n2]);
		if(n2<strlen(s)-1)
		printf(".");
		for(i=n2+1;i<strlen(s);i++)
		{
			printf("%c",s[i]);
		}
		p=m-n2;
		printf("e%d",p);
	}
	return 0;
 } 

