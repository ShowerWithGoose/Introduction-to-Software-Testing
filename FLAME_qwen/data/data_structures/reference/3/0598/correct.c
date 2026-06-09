#include <stdio.h>
#include <stdlib.h>

struct decStr
{
	char* base;
	int exponent;
};

int lenStr(char* str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}
struct decStr decStr(char* str)
{
	int head = 0;
	int tail = lenStr(str) - 1;
	int point = 0;
	int len = 0;
	while (str[head] == '0' || str[head] == '.') head++;
	if (str[head] == '\0')//基数は0である場合
	{
		char* base = 0;
		int exponent = 0;
		struct decStr decStr;
		decStr.base = base;
		decStr.exponent = exponent;
		return decStr;
	}
	while (str[tail] == '0' || str[tail] == '.') tail--;
	while (str[point] != '.') point++;
	int exponent = head > point ? point - head : point - head - 1;
	while (head != tail)
	{
		if (str[tail] >= '0' && str[tail] <= '9')
		{
			len++;
		}
		tail--;
	}
	if (str[head] >= '0' && str[head] <= '9')
	{
		len++;
	}
	char* base = (char*)malloc((len + 1) * sizeof(char));
	int i = 0;
	while (len)
	{
		if (str[head] >= '0' && str[head] <= '9')
		{
			base[i++] = str[head++];
			len--;
		}
		else
			head++;
	}
	base[i] = '\0';
	struct decStr decStr;
	decStr.base = base;
	decStr.exponent = exponent;
	return decStr;
}
void prtDecStr(struct decStr decStr)
{
	if (!decStr.base)
	{
		printf("%c", '0');
	}
	else
	{
		if (decStr.base[1] == '\0')
		{
			printf("%c", decStr.base[0]);
		}
		else
		{
			printf("%c.%s", decStr.base[0], decStr.base + 1);
		}
	}
	printf("e");
	printf("%d\n", decStr.exponent);
}

int main()
{
	char str[1000];
	gets(str);
	struct decStr dec = decStr(str);
	prtDecStr(dec);
	return 0;
}
