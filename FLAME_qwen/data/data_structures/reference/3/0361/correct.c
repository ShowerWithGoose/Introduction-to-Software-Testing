#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

char s[105];
int main (void)
{
	scanf("%s",s);
	int i,j,k;
	int len=strlen(s);
	if(s[0]=='0')
	{
		for(i=2;s[i]=='0';i++);
		int n=i-1;
		printf("%c",s[i]);
		if(i<len-1)
			printf(".");
		for(j=i+1;s[j];j++)
			printf("%c",s[j]);
		printf("e-%d",n);
	}
	else
	{
		for(i=0;s[i]!='.'&&s[i];i++);
		int n=i-1;
		printf("%c",s[0]);
		if(len>1)
			printf(".");
		for(i=1;s[i];i++)
		{
			if(s[i]!='.')
				printf("%c",s[i]);
		}
		printf("e%d",n);
	}
    return 0;
}


