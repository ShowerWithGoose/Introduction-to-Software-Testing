#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct tongji
{
	char word[100];
	int  count;
};
struct tongji cipin[1000];
int cmp(const void* p1, const void* p2)
{
	struct tongji* a = (struct tongji*)p1;
	struct tongji* b = (struct tongji*)p2;
	return strcmp(a->word, b->word);
}
char s[100];
int main()
{
	int i=0, j=0, k = 0, l=0, m=0, n=0,q=0;
	FILE *fp1;
	fp1 = fopen("article.txt", "r");
	if (fp1 == NULL)
	{
		perror("can not open the file\n");
	}
	while (fscanf(fp1, "%s", s) != EOF)
	{

		for (i = 0; s[i] != '\0'; i++)
		{    
			if ('a' <= tolower(s[i]) && tolower(s[i]) <= 'z')
			{
				l = 0;
				cipin[k].word[l] = tolower(s[i]);
				cipin[k].count = 1;
				l++;
				for (j = i + 1;  s[j] != '\0'; j++)
				{  
					if ('a' <= tolower(s[j]) && tolower(s[j]) <= 'z')
					{
						cipin[k].word[l] = tolower(s[j]);
						l++;
						m = j;
						i = m;
					}
					else break;	
				}
				for (n = k; n >=0; n--)
				{
					for (j = n-1; j >=0; j--)
					{
						if (strcmp(cipin[n].word, cipin[j].word) == 0)
						{
							cipin[n].count+=cipin[j].count;
							cipin[j].count = 0;
						}
					}
				}	
			}
			k++;
		}
		
	}
	qsort(cipin, k, sizeof(cipin[0]), cmp);
	for (i = 0; i <= k; i++)
	{
		if (cipin[i].count!=0)
		{
			printf("%s %d\n", cipin[i].word, cipin[i].count);
		}
	}
	return 0;
}
