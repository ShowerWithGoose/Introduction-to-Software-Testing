#include <stdio.h>
#define MAXLENGTH 1000
int expand_judge(char before_hyphen, char after_hyphen);
int main(void)
{
	char short_str[MAXLENGTH], long_str[MAXLENGTH];
	fgets(short_str, MAXLENGTH, stdin);
	int i = 0, j = 0;
	while (short_str[i] != '\0')
	{
		if (short_str[i + 1] == '-' && expand_judge(short_str[i], short_str[i + 2]) == 1)
		{
			for (char k = short_str[i]; k < short_str[i + 2]; k++)
			{
				long_str[j++] = k; // equivalent to long_str[j]=k j++
			}
			i += 2;
		}
		else
		{
			long_str[j++] = short_str[i++];
		}
	}
	long_str[j] = '\0';
	printf("%s", long_str);
	return 0;
}

int expand_judge(char before_hyphen, char after_hyphen)
{
	if (before_hyphen >= 'A' && after_hyphen <= 'Z' && before_hyphen < after_hyphen)
		return 1;
	else if (before_hyphen >= 'a' && after_hyphen <= 'z' && before_hyphen < after_hyphen)
		return 1;
	else if (before_hyphen >= '0' && after_hyphen <= '9' && before_hyphen < after_hyphen)
		return 1;
	else
		return 0;
}
