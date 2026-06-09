#include <stdio.h>
#include <string.h>
char s[10001];

int main()
{
	char c;
	scanf("%s", s);
	int i = 0;
	
	for(i = 0; i < strlen(s); i++)
	{
		if(s[i] == '-')
		{
			if('0' <= s[i-1] && s[i-1] < s[i+1] && s[i+1] <= '9')
			{
				for(c = s[i-1] + 1; c < s[i+1]; c++)
					printf("%c", c); 
			}
			else if('A' <= s[i-1] && s[i-1] < s[i+1] && s[i+1] <= 'Z')
			{
				for(c = s[i-1] + 1; c < s[i+1]; c++)
					printf("%c", c); 
			}
			else if('a' <= s[i-1] && s[i-1] < s[i+1] && s[i+1] <= 'z')
			{
				for(c = s[i-1] + 1; c < s[i+1]; c++)
					printf("%c", c); 
			}
			else
				printf("%c",s[i]);
		}
		else
			printf("%c", s[i]);
	}
	return 0;
} 

