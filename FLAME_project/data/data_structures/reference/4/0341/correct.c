#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:6031)

struct voc
{
	char word[25];
	int time;
}words[10000];


int cmp(const void* a, const void* b)
{
	struct voc* aa = (struct voc*)a;
	struct voc* bb = (struct voc*)b;
	return strcmp(aa->word, bb->word);
}

int main()
{
	FILE* in;
	in = fopen("article.txt", "r");
	int i = 0, j = 0, flag = 1;
	int c;
	while ((c = fgetc(in)) != EOF)
	{
		c = tolower(c);
		if ((c < 97 || c>122) && flag == 1)
			continue;
		if(c >= 97 && c <= 122)
		{
			words[i].word[j] = c;
			flag = 0;
			j++;
		}
		else
		{
			words[i].word[j] = '\0';
			for (int k = 0; k < i; k++)
			{
				if (strcmp(words[i].word, words[k].word) == 0)
				{
					i--;
					words[k].time++;
					break;
				}
			}
			i++;
			j = 0;
			flag = 1;
		}
	}	
	qsort(words, i, sizeof(words[0]), cmp);
	for (int j = 0; j < i; j++)
		printf("%s %d\n", words[j].word, words[j].time + 1);
	return 0;
}
