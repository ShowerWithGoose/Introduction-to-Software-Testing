#include <stdio.h>
#include <string.h>
#define MAXLENGTH 150
int main(void)
{
	char data[MAXLENGTH];
	scanf("%s", data);
	int len = strlen(data);
	
	int before_dot = 0;
	int after_dot;
	while (data[before_dot] != '.')
		before_dot++;
	after_dot = len - before_dot - 1;

	if (before_dot != 1) //小数点前的位数多于一位
	{
		printf("%c.", data[0]);
		for (int i = 1; i < len; i++)
		{
			if (data[i] != '.')
				printf("%c", data[i]);
		}
		printf("e%d", before_dot - 1);
	}
	else //小数点前只有一位
	{
		if (data[0] != '0') //小数点前的一位不是0
		{
			printf("%se0", data);
		}
		else //小数点前的一位是0
		{
			int flag;
			for (int i = 2; i < len; i++)
			{
				if (data[i] != '0')
				{
					flag = i;
					break;
				}
			}
			if (flag + 1 == len) //只有一位非零
			{
				printf("%ce-%d", data[flag], after_dot);
			}
			else
			{
				printf("%c.", data[flag]);
				for (int i = flag + 1; i < len; i++)
				{
					printf("%c", data[i]);
				}
				printf("e-%d", flag - 1);
			}
		}
	}
	//printf("%d %d", before_dot, after_dot);
	return 0;
}
