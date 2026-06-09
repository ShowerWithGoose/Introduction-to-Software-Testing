#include <stdio.h>
#include <string.h>
int main()
{
	char line[10086];
	char k;
	int len, i;
	gets(line);
	len = strlen(line);
	for (i = 0; i <= len; i++)
	{
		if (line[i] == '-')
		{ 
			for (k = line[i - 1] + 1; k < line[i + 1]; k++)
			{
				if(line[i - 1] >= 48 && line[i + 1] <= 57 || line[i - 1] >= 65 && line[i + 1] <= 90 || line[i - 1] >= 97 && line[i + 1] <= 122)
					printf("%c", k);
				else
					{
						printf("-");
						break;
					}
			}
		}
		else
			printf("%c", line[i]);
	}
	return 0;
}

