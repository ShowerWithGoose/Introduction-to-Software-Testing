#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100000

char s[MAXN];

int main()
{
	gets(s);
	char *p=strstr(s,"."),*q=s;
	if(p==NULL)
	{
		puts(s);
		return 0;
	}
	while(*q=='0' || *q=='.')	q++;
	int e=(p-q>0)?p-q-1:p-q;
	printf("%c",*q);
	if(*(q+1)!='\0')	printf(".");
	while(*(++q)!='\0')
		if(*q!='.')
			printf("%c",*q);
	printf("e%d",e);
	return 0;
}

