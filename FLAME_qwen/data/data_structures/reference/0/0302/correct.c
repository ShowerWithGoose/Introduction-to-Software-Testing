#include <stdio.h>
#include <string.h>
char s[114514];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	int i;
	char j;
	for(i=0;i<len;i++)
	{
		if(('0'<=s[i]&&s[i]<='9')&&s[i+1]=='-'&&('0'<=s[i+2]&&s[i+2]<='9')&&s[i]<s[i+2])
			{
				for(j=s[i];j<s[i+2];j++)
				printf("%c",j);
				i++;
			}
		else if(('a'<=s[i]&&s[i]<='z')&&s[i+1]=='-'&&('a'<=s[i+2]&&s[i+2]<='z')&&s[i]<s[i+2])
			{
				for(j=s[i];j<s[i+2];j++)
				printf("%c",j);
				i++;
			}
		else if(('A'<=s[i]&&s[i]<='Z')&&s[i+1]=='-'&&('A'<=s[i+2]&&s[i+2]<='Z')&&s[i]<s[i+2])
			{
				for(j=s[i];j<s[i+2];j++)
				printf("%c",j);
				i++;
			}
		else
			printf("%c",s[i]);
	}
}

