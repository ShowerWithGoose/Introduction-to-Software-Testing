#include<stdio.h>
#include<string.h>
char a[10000];
int main()
{
	gets(a);
	int i,q;
	char b='.';
	if(a[0]!='0')
	{
		printf("%c.",a[0]);
		for(i=1;i<strlen(a);i++)
		{
			if(a[i]!='.')
			printf("%c",a[i]);
		}
		q=strchr(a,b)-a-1;
		printf("e%d",q);
	}
	else if(a[0]=='0')
	{
		q=1;
		for(i=2;a[i]=='0';i++)
		q++;
		printf("%c",a[i]);
		if(a[i+1]!='\0')
		printf(".");
		i++;
		for(;a[i]!='\0';i++)
		printf("%c",a[i]);
		printf("e-%d",q);
	}
	return 0;
}

