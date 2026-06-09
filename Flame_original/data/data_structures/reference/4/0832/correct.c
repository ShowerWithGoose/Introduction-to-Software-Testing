#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
typedef struct {
	char words[50];
	int num;
}line;
line wor_cn[1000];
char inwords[1000], putin[1000];
int s;
int cmp(const void* a, const void* b)
{
	line* p = (line*)a;
	line* q = (line*)b;
	return strcmp(p->words, q->words);
}
int main()
{
	FILE* in;
	in = fopen("article.txt", "r");
	/*in = stdin;*/
	int n = 0, i, j, k, len, t;
	while ((fgets(putin,1000,in)) != NULL)
	{
		int l = strlen(putin), s1, s2;
		for (i = 0; i < l; i++)
		{
			if (isalpha(putin[i]) && !isalpha(putin[i - 1]))
			{
				s1 = i;
				for (j = s1; j < l && isalpha(putin[j]); j++)
				{
					if (isalpha(putin[j]) && !isalpha(putin[j + 1]))
					{
						s2 = j;
						for (k = s1; k <= s2; k++)
						{
							inwords[k - s1] = putin[k];
						}
						len = strlen(inwords);
						for (t = 0; t < len; t++)
						{
								inwords[t] = tolower(inwords[t]);
						}
						i = j = s2;
						strcpy(wor_cn[n].words, inwords);
						memset(inwords, '\0', 1000);
						wor_cn[n].num = 1;
						n++;
					}
				}
			}
		}
		
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (strcmp(wor_cn[i].words, wor_cn[j].words) == 0)
			{
				wor_cn[j].num++;
				for (k = i; k < n; k++)
				{
					strcpy(wor_cn[k].words, wor_cn[k + 1].words);
					wor_cn[k].num = wor_cn[k + 1].num;
				}
				i--;  n--; k--;
			}
		}
	}
	qsort(wor_cn, n, sizeof(line), cmp);
	for (i = 0; i < n; i++)
	{
		printf("%s %d\n", wor_cn[i].words, wor_cn[i].num);
	}
	fclose(in);
	return 0;
}
