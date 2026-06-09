#include<stdio.h>
int main()
{
	char s[105]={};
	int xq=0, xh=0, i, j, flag=0;
	int z[105]={0}, x[105]={0};
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
			flag=1;
		if(flag==1&&s[i]<='9'&&s[i]>='0')
			x[xh++]=s[i]-'0';
		if(flag==0&&s[i]<='9'&&s[i]>='0')
			z[xq++]=s[i]-'0';
	}
	if(z[0]==0)
	{
		for(i=0;x[i]==0;i++);
		if(s[0]=='-')
			printf("-%d",x[i]);
		else
			printf("%d",x[i]);
		if(i<xh-1)
			printf(".");
		for(j=i+1;j<xh;j++)
			printf("%d",x[j]);
		printf("e-%d",i+1);
	}
	else
	{
		if(s[0]=='-')
			printf("-%d.",z[0]);
		else
			printf("%d.",z[0]);
		for(i=1;i<xq;i++)
			printf("%d",z[i]);
		for(i=0;i<xh;i++)
			printf("%d",x[i]);
		printf("e%d",xq-1);
	}
	
	return 0;
	
}

