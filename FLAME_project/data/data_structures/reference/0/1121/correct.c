#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	int i,j;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-')
		{
			if('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z'&&s[i-1]<s[i+1])
			{
				for(j=1;j<s[i+1]-s[i-1];j++)
				printf("%c",s[i-1]+j);
			}
			else if('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z'&&s[i-1]<s[i+1])
			{
				for(j=1;j<s[i+1]-s[i-1];j++)
				printf("%c",s[i-1]+j);
			}
			else if('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9'&&s[i-1]<s[i+1])
			{
				for(j=1;j<s[i+1]-s[i-1];j++)
				printf("%c",s[i-1]+j);
			}
			else
			printf("%c",s[i]);
		}
		else
		printf("%c",s[i]);
	}
	return 0;
}



