#include <stdio.h>
#include <ctype.h>
char c[500000];
int main()
{
	scanf("%s", c);
	printf("%c", c[0]);
	for (int i = 1; c[i] != '\0'; i++)
	{
		if (c[i] == '-' && c[i - 1] < c[i + 1] && ((islower(c[i - 1]) && islower(c[i + 1])) || (isupper(c[i - 1]) && isupper(c[i + 1])) || (isdigit(c[i - 1]) && isdigit(c[i + 1]))))
		{
			for (int j = c[i - 1] + 1; j < c[i + 1]; j++)
			{
				printf("%c", j + '\0');
			}
		}
		else
		{
			printf("%c", c[i]);
		}
	}
	return 0;
}


