#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char data[1000];
	int i, j;
	gets(data);
	for (i = 0; i < strlen(data); i++)
	{
		if (data[i] != '-')
		{
			printf ("%c", data[i]);
		}
		else if (data[i - 1] >= '0' && data[i + 1] <= '9' && data[i - 1] < data[i + 1])
		{
			for (j = 1; j < data[i + 1] - data[i - 1]; j++)
			{
				printf ("%c", data[i - 1] + j);
			}
		}
		else if (data[i - 1] >= 'a' && data[i + 1] <= 'z' && data[i - 1] < data[i + 1])
		{	
			for (j = 1; j < data[i + 1] - data[i - 1]; j++)
			{
				printf ("%c", data[i - 1] + j);
			}
		}
		else if (data[i - 1] >= 'A' && data[i + 1] <= 'Z' && data[i - 1] < data[i + 1])
		{
			for (j = 1; j < data[i + 1] - data[i - 1]; j++)
			{
				printf ("%c", data[i - 1] + j);
			}
		}
		else
		{
			printf ("-");
		}	
	}
	return 0;
}




