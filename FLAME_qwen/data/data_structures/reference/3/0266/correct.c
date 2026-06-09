#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char str[1000];
	gets(str);
	if(strchr(str,'.')==NULL)
	{
		putchar(str[0]);
		if(strlen(str)>1)
		putchar('.');
		for(i=1;i<strlen(str);i++)
		putchar(str[i]);
		printf("e%d",strlen(str)-1);
		return 0;
	}
	if(str[0]=='0')
	{
		for(i=2;str[i]=='0';i++);
		j=i-1;
		putchar(str[i]);
		if(str[i+1]!='\0')
		{
		putchar('.');
		for(i++;i<strlen(str);i++)
		putchar(str[i]);}
		printf("e%d",-j);
		return 0;
	}
	for(i=0;str[i]!='.';i++);
	j=i-1;
	putchar(str[0]);
	putchar('.');
	for(i=1;i<strlen(str);i++)
	if(str[i]!='.')
	putchar(str[i]);
	printf("e%d",j);
	return 0;
 } 

