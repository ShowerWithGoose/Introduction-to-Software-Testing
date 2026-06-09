#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[300];
int main()
{
	char ch;
	int i=0,n;
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]=='-')
		{
			if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1])
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
				{
					printf("%c",ch);
				}
			}
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
				{
					printf("%c",ch);
				}
			}
			else if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1])
			{
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
				{
					printf("%c",ch);
				}
			}
			else
			{
				printf("%c",s[i]);
			}
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	return 0;
}
