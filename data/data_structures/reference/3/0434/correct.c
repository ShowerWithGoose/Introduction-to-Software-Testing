#include <stdio.h>
#include <string.h>

char s[105];
int main ()
{
	int i,j,len;
	scanf("%s",s);
	len=strlen(s);
	
	if (s[0]!='0'&&s[1]=='.')
	printf("%se0",s);
	else if (s[0]=='0'&&s[1]=='.')
	{
		for (i=0;s[2+i]=='0';i++);
		if (i+3<len)
		{
			printf("%c.",s[i+2]);
			for(j=i;(2+j)<len-1;j++)
			printf("%c",s[3+j]);
			printf("e-%d",i+1);
		}
		else
		{
			printf("%c",s[i+2]);
			printf("e-%d",i+1);
		}
	}
	else
	{
		for (i=3;s[i]!='.';i++);
		printf("%c.",s[0]);
		for (j=1;j<i;j++)
		printf("%c",s[j]);
		for (j=i+1;j<len;j++)
		printf("%c",s[j]);
		printf("e%d",i-1);
	}
	return 0;
}


