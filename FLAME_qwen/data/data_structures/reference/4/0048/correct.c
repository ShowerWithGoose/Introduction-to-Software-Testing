#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000000

struct Word
{
	char spell[1000];
	int time; 
} word[MAXSIZE], word_temp;

int main()
{
	int num = 0;
	FILE *file;
	file = fopen("article.txt", "r");
	if (file == NULL)
	{
		printf ("open error!\n");
		return 0;
	}
	char str[MAXSIZE], empty[1000];
	int i, j, k, strat, length = 0;
	while (fgets(str, MAXSIZE, file) != NULL)
	{
		for (i = 0; i < strlen(str); i++)
		{
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			{
				if (length == 0)
				{
					strat = i;
					length++;
				}
				else
				{
					length++;
				}
			}
			else
			{
				if (length != 0)
				{
					char temp[1000];
					int flag = 0;
					j = 0;
					for (k = strat; k < strat + length; k++)
					{
						if (str[k] >= 'a' && str[k] <= 'z')
						{
							temp[j] = str[k];
							j++;
						}
						else
						{
							temp[j] = str[k] + 32;
							j++;
						}
					}
					for (k = 0; k < num; k++)
					{
						if (strcmp(temp, word[k].spell) == 0)
						{
							word[k].time++;
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						strcpy(word[num].spell, temp);
						word[num].time = 1;
						num++;
					}
					memset(temp, '\0', sizeof(temp));
					length = 0;
				}
			} 
		}
	}
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (strcmp(word[j].spell, word[j + 1].spell) > 0)
			{
				word_temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = word_temp;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		printf ("%s %d\n", word[i].spell, word[i].time);
	}
	fclose(file);
	
	return 0; 
}




