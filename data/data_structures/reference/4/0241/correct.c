#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[100][20];
char c;
char temp[100];
int count[100];
int jilu[100];
int main()
{
	FILE* fp;
	fp = fopen("article.txt", "r");
	c = fgetc(fp);
	int i = 0, j = 0;
	while (c != EOF)
	{
		if (isalpha(c))
		{

			c = tolower(c);
			a[i][j] = c;
			j++;
		}
		else if (ispunct(c) || isspace(c))
		{
			a[i][j] = '\0';
			j = 0;
			i++;
		}

		c = fgetc(fp);
	}
	for (int t = 0; t < i - 1; t++)
	{
		for (int ling = 0; ling < i - 1 - t; ling++)
		{
			if (strcmp(a[ling], a[ling + 1]) > 0)
			{
				strcpy(temp, a[ling]);
				strcpy(a[ling], a[ling + 1]);
				strcpy(a[ling + 1], temp);
			}
		}
	}

	for (int t = 0; t < i; t++)
	{
		count[t] = 1;
		if (jilu[i] == 0 && a[t][0] != '\0')
		{
			for (int ling = t + 1; ling < i; ling++)
			{
				if (strcmp(a[t], a[ling]) == 0)
				{
					count[t]++;
					jilu[ling] = 1;
				}
			}
		}
	}
	for (int t = 0; t < i; t++)
	{
		if (jilu[t] == 0 && a[t][0] != '\0')
		{
			printf("%s %d\n", a[t], count[t]);
		}
	}
	fclose(fp);
}



