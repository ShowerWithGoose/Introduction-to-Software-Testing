#include<stdio.h>
#include<string.h> 
int main()
{
	char s[120];
	gets(s);
	int i, j, l, k, m;
	if(s[0] == '0')
	{
		for(i = 0; i < strlen(s); i++)
		{
			if(s[i] != '0' && s[i] != '.')break;
		}
		printf("%c", s[i]);
		if(i + 1 < strlen(s))
		{
			printf(".");
			for(l = i + 1; l < strlen(s); l++)
			{
				printf("%c", s[l]);
			}
		}
		else;
		printf("e-%d", i - 1);
	}
	else
	{
		if(strlen(s) == 1)printf("%ce0");
		else if(s[1] == '.')printf("%se0", s);
		else
		{
			for(k = 0; k < strlen(s);k++)
			{
				if(s[k] == '.')break;
			}
			printf("%c.", s[0]);
			for(m = 1; m < k; m++)
			{
				printf("%c", s[m]);
			}
			for(m = k + 1; m < strlen(s); m++)
			{
				printf("%c", s[m]);
			}
			printf("e%d", k - 1);
		}
	}
}

