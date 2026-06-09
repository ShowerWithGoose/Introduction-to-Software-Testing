#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char s[1000005]; 

int main()
{
	int i, l;
	char j;
	 gets(s);
	 l = strlen(s);
	for (i = 0; i < l; i++)
	{
		if (s[i] == '-')
		{
			if ((isdigit(s[i-1])&&isdigit(s[i+1]))||(isupper(s[i-1])&&isupper(s[i+1]))||(islower(s[i-1])&&islower(s[i+1]))&&s[i-1] < s[i+1])
			{
				for (j = s[i-1]+1; j < s[i+1]; j++)
				{
					printf("%c", j);
				}
			}
			else
			{
				printf("-");
			}
		}
		else
		{
			printf("%c", s[i]);
		}
	}
	return 0;
}


