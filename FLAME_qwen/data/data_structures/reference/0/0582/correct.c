#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
	char ip[10000], op[10000];
	gets(ip);int i = 0, j = 0;
	int lenall = strlen(ip);
	int len;
	for (;i<lenall;)
	{
		if (ip[i] != '-')
		{
			op[j++] = ip[i++];

		}
		else
		{
			if (ip[i - 1] < ip[i + 1])
			{
				len = ip[i + 1] - ip[i - 1] - 1;
				if (islower(ip[i - 1]) && islower(ip[i + 1]))
				{
					for (int k = 1;k <= len;k++)
					{
						op[j] = op[j - 1] + 1;j++;
					}
				}
				else if (isupper(ip[i - 1]) && isupper(ip[i + 1]))
				{
					for (int k = 1;k <= len;k++)
					{
						op[j] = op[j - 1] + 1;j++;
					}
				}
				else if (isdigit(ip[i - 1]) && isdigit(ip[i + 1]))
				{
					for (int k = 1;k <= len;k++)
					{
						op[j] = op[j - 1] + 1;j++;
					}
				}
				else op[j++] = '-';
				i++;
			}

		}
		op[j] = '\0';
	}
	puts(op);
}
