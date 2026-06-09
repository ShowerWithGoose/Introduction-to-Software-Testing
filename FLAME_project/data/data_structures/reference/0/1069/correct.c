#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-6
#define EMP struct employee
char buf[BUFSIZ];
int main()
{
	char s[500];
	gets(s);
	int i,k,j,f=0;
	for(i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]=='-'&&((s[i-1]>='A'&&s[i+1]>s[i-1]&&s[i+1]<='Z')||(s[i-1]>='a'&&s[i+1]>s[i-1]&&s[i+1]<='z')||(s[i-1]>='0'&&s[i+1]>s[i-1]&&s[i+1]<='9')))
		{
			for(j=s[i-1]+1;j<s[i+1];j++)
			{
				printf("%c",j);
			}
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}



