#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000];
	scanf("%s", str);
	int StrLen = strlen(str);
	for (int i = 0; i < StrLen; i++)
	{
		if ('-' == str[i])
		{
			char left = str[i - 1], right = str[i + 1];
			int a = (left <= '9' && right <= '9');
			int b = (left >= 'a' && right >= 'a');
			int c = ((left <= 'Z' && right <= 'Z') && (left >= 'A' && right >= 'A'));
			if (a || b || c)
			{
				int add = right - left - 1;
				int p = StrLen + add - 1;
				int x = StrLen - i;
				for (int j = 0; j < x; j++)
				{
					str[p - j] = str[StrLen - j];
				}
				for (int j = left + 1; j <= right - 1; j++)
				{
					str[i++] = (char)j;
				}
			}
			StrLen += right - left - 2;
		}
	}
	printf("%s", str);
	return 0;
}



