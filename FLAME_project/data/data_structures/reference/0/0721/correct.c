#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[80];
	scanf("%s", s);
	int a = 0, b = 0, c = 0, i;
	for(i = 0; i < strlen(s) - 1; i++)
	{
		if(s[i] == '-')
		{
			if(s[i + 1] > s[i - 1]) 
			{
				if(isdigit(s[i - 1]) && isdigit(s[i + 1]))
				{
					for(a = s[i - 1] + 1; a < s[i + 1]; a++)
					{
						printf("%c", a);
					}
				}
				else if(islower(s[i - 1]) && islower(s[i + 1]))
				{
					for(b = s[i - 1] + 1; b < s[i + 1]; b++)
					{
						printf("%c", b);
					}
				}
				else if(isupper(s[i - 1]) && isupper(s[i + 1]))
				{
					for(c = s[i - 1] + 1; c < s[i + 1]; c++)
					{
						printf("%c", c);
					}
				}
				else printf("%c", s[i]);
			}
			else printf("%c", s[i]);
		}
		else
		{
			printf("%c", s[i]);
		}
	}
	printf("%c", s[strlen(s) - 1]);
 } 



