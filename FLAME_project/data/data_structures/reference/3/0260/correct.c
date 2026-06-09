#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0};
	int i,j,z;
	scanf("%s",&s);
	if(s[0]=='0')
	{
	for(j=0;s[j]=='0'||s[j]=='.';j++);
	z=1-j;
	printf("%c",s[j]);
	if(strlen(s)!=j+1)
	printf(".");
	for(j=j+1;j<strlen(s);j++)
	printf("%c",s[j]);
	printf("e%d",z);		
	}
	if(s[0]!='0')
	{
		printf("%c.",s[0]);
	for(j=1;j<strlen(s);j++)
	{
	if(s[j]!='.')
	printf("%c",s[j]);
	else
	z=j-1;
	}
	printf("e%d",z);
	}
	return 0;
}

