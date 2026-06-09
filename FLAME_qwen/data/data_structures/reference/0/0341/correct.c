#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char s[10000];
char t[10000];
int isSameType(int n)
{
	if (s[n - 1] >= 48 && s[n - 1] <= 57 && s[n + 1] >= 48 && s[n + 1] <= 57)
		return 1;
	else if (s[n - 1] >= 65 && s[n - 1] <= 90 && s[n + 1] >= 65 && s[n + 1] <= 90)
		return 1;
	else if (s[n - 1] >= 97 && s[n - 1] <= 122 && s[n + 1] >= 97 && s[n + 1] <= 122)
		return 1;
	else
		return 0;
}

int main()
{
	gets(s);
	int i = 1, n = 0;
	t[0] = s[0];
	while (s[i] != '\0')
	{
		if (s[i] == '-' && isSameType(i) == 1)
		{
			for (int j = 0; j < s[i + 1] - s[i - 1]; j++)
				t[i + j + n] = s[i - 1] + j + 1;
			n += s[i + 1] - s[i - 1] - 2;
			i ++;
		}
		else
			t[i + n] = s[i];
		i++;
	}
	puts(t);
	return 0;
}



