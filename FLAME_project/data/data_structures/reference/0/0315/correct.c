#include <stdio.h>
#include <string.h>
char s[1005];
int main()
{
	scanf("%s",s);
	int l = strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i] != '-')
			printf("%c",s[i]);
		else
		{
			if(((('0'<=s[i-1]&&s[i-1]<='9')&&('0'<=s[i+1]&&s[i+1]<='9'))||(('a'<=s[i-1]&&s[i-1]<='z')&&('a'<=s[i+1]&&s[i+1]<='z'))||(('A'<=s[i-1]&&s[i-1]<='Z')&&('A'<=s[i+1]&&s[i+1]<='Z')))&&(s[i-1]<s[i+1]))
			{
				for(char c = s[i-1]+1;c<s[i+1];c++)
					printf("%c",c);
			}
			else
				printf("-");
		}
	}
	return 0;
}

//((('0'<=s[i-1]&&s[i-1]<='9')&&('0'<=s[i+1]&&s[i+1]<='9'))||(('a'<=s[i-1]&&s[i-1]<='z')&&('a'<=s[i+1]&&s[i+1]<='z'))||(('A'<=s[i-1]&&s[i-1]<='Z')&&('A'<=s[i+1]&&s[i+1]<='Z')))&&(s[i-1]<s[i+1])



