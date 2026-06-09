#include <stdio.h>
#include <string.h>

int main()
{
	char data[200];
	int i, site1, site2, flag = 0;
	gets(data);
	for (i = 0; i < strlen(data); i++)
	{
		if (data[i] != '0' && flag == 0 && data[i] != '.')
		{
			site1 = i;
			flag = 1;
		}
		else if (data[i] == '.')
		{
			site2 = i;
		}
	}
	if (site1 < site2)
	{
		for (i = 0; i < strlen(data); i++)
		{
			if (i == 1)
			{
				printf (".");
			}
			if (data[i] != '.')
			{
				printf ("%c", data[i]);
			}
		}
		printf ("e%d", site2 - 1);
	}
	else
	{
		for (i = site1; i < strlen(data); i++)
		{
			if (i == site1 + 1)
			{
				printf (".");
			}
			if (data[i] != '.')
			{
				printf ("%c", data[i]);
			}
		}
		printf ("e%d", -(site1 - 1));
	}
	return 0;
}




