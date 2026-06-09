#include<stdio.h>
#include<string.h>
int main()
{
	char s[2000];
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		if (s[i + 1] != '-')
		{
			printf("%c", s[i]);
		}
		else
		{
			if (('0' <= s[i] && s[i] < s[i + 2] && s[i + 2] <= '9') || ('a' <= s[i] && s[i] < s[i + 2] && s[i + 2] <= 'z') || ('A' <= s[i] && s[i] < s[i + 2] && s[i + 2] <= 'Z'))
			{
				for (char tim = s[i]; tim < s[i + 2]; tim++)
				{
					printf("%c", tim);
				}
				i = i + 1;
			}
			else
			{
				printf("%c", s[i]);
			}
		}
	}
	return 0;
}
