#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
	char word[50];
	int num;
};


struct node arr[1000];

int cmp(const void* a, const void* b)
{
	struct node* p1 = (struct node*)a;
	struct node* p2 = (struct node*)b;
	return strcmp(p1->word, p2->word);
}

int main()
{
	FILE* fp1 = fopen("article.txt", "r");

	if (fp1 == NULL)
	{
		return 1;
	}


	int count = 0;

	char ch;
	int n = 0;
	char line[1024] = { 0 };

	ch = fgetc(fp1);
	while (ch != EOF)
	{
		line[n] = ch;
		n++;
		ch = fgetc(fp1);
	}



	for (int i = 0; i < strlen(line); i++)
	{
		if (isalpha(line[i]))
		{
			int len = 0;
			int j = 0;
			for (j = i; j < strlen(line); j++)
			{
				if (isalpha(line[j]))
				{
					arr[count].word[len] = tolower(line[j]);
					len++;
				}
				else
				{
					break;
				}

			}
			i = j;
			arr[count].word[len + 1] = '\0';
			arr[count].num = 1;
			count++;
		}
	}



	int tot = count;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (strcmp(arr[i].word, arr[j].word) == 0)
			{
				arr[i].num++;
				memset(&arr[j].num, 0, sizeof(int));
				memset(arr[j].word, 0, sizeof(char) * 50);
				tot--;
			}
		}
	}

	qsort(arr, count, sizeof(struct node), cmp);

	for (int i = 0; i < count; i++)
	{
		if (strlen(arr[i].word) > 0)
		{
			printf("%s %d\n", arr[i].word, arr[i].num);
		}
	}

	fclose(fp1);

	return 0;
}
