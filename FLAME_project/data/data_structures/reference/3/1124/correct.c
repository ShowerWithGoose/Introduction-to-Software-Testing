#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	int m=0,n=0,i,flag=0;//m为小数点位数，n为第一个不为零的位数； 
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='0'&&s[i]!='.'&&flag==0)
		{
			n=i;
			flag=1;
		}
		else if(s[i]=='.')
		m=i;
	} 
	if(m==0)
	{
		if(strlen(s)==1)
		{
			printf("%ce0",s[0]);
			return 0;
		}
		else
		{
			printf("%c.",s[0]);
			for(i=1;i<strlen(s);i++)
			printf("%c",s[i]);
            printf("e%d",strlen(s)-1);
            return 0;
		}
	}
	if(strlen(s)-n==1)
	printf("%c",s[n]);
	else
	printf("%c.",s[n]);
	for(i=n+1;i<strlen(s);i++)
	{
		if(s[i]!='.')
		printf("%c",s[i]);
	}
	if(m<n)
	printf("e%d",m-n);
	if(m>n)
	printf("e%d",m-n-1);
	return 0;
}


