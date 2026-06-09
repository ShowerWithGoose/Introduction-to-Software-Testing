#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
	char s[5000];
	scanf("%s",&s);
	
	int i = 0;
	
	for(i = 0; i < strlen(s); i ++)
	{
		if(s[i] == '-')
		{
			if(islower(s[i - 1]))
			{
				if(islower(s[i + 1]))
				{
					while((s[i - 1] - s[i + 1])< 0)
					{
						printf("%c",s[i - 1]);
						s[i - 1] = s[i - 1] + 1;
					}
				}
				else
				{
					printf("%c%c",s[i - 1],s[i]);
				}	
			}
			else if(isupper(s[i - 1]))
			{
				if(isupper(s[i + 1]))
				{
					while((s[i - 1] - s[i + 1])< 0)
					{
						printf("%c",s[i - 1]);
						s[i - 1] = s[i - 1] + 1;
					}
				}
				else
				{
					printf("%c%c",s[i - 1],s[i]);
				}		
			}
			else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
			{
				if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
				{
					while((s[i - 1] - s[i + 1])< 0)
					{
						printf("%c",s[i - 1]);
						s[i - 1] = s[i - 1] + 1;
					}
				}
				else
				{
					printf("%c%c",s[i - 1],s[i]);
				}		
			}
		}
		else if(s[i + 1] != '-')
		{
			printf("%c",s[i]);
		}
	}
	return 0;
}

