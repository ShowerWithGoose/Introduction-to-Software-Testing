#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
char s[10000];
int i,j;
scanf("%s",s);
for(i=0;s[i]!='\0';i++)
{
	if(s[i]=='-'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i-1]<='9'&&s[i-1]<s[i+1])
	{
		for(j=s[i-1]+1;j<s[i+1];j++)
		{
			printf("%c",j);
	    }
	    continue;
	}
	if(s[i]=='-'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]>='a'&&s[i-1]<='z'&&s[i-1]<s[i+1])
	{
		for(j=s[i-1]+1;j<s[i+1];j++)
		{
			printf("%c",j);
		}
		continue;
	}
	if(s[i]=='-'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]>='A'&&s[i-1]<='Z'&&s[i-1]<s[i+1])
	{
		for(j=s[i-1]+1;j<s[i+1];j++)
		{
			printf("%c",j);
		}
		continue;
	}
	else
	{
		printf("%c",s[i]);
	}
}
return 0;
}



