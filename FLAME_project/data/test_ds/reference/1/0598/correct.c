#include <stdio.h>

#define LOW (0)
#define CAP (1)
#define NUM (2)
#define NON (-1)

int getType(char c)
{
	if (c >= 'a' && c <= 'z')
		return LOW;
	if (c >= 'A' && c <= 'Z')
		return CAP;
	if (c >= '0' && c <= '9')
		return NUM;
	return NON;
}

int main()
{
	char str[1000];
	char exp[1000];
	char ch;
	gets(str);
	int i;
	int j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-' && i > 0)
		{
			if (getType(str[i - 1]) == getType(str[i + 1]) && getType(str[i - 1]) != NON && str[i - 1] < str[i + 1])
			{
				for (ch = str[i - 1] + 1; ch < str[i + 1]; ch++)
				{
					exp[j++] = ch;
				}
			}
			else
			{
				exp[j++] = str[i];
			}
		}
		else
		{
			exp[j++] = str[i];
		}
		exp[j] = '\0';
	}
	puts(exp);
	return 0;
}
