#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void load();
void func();
void print();
int cmp(const void *, const void *);

typedef struct{
	char word[99];
	int count;
}_books;

FILE *input;
_books books[114514];
int count_i;

int main()
{
	load();
	func();
	print();
	fclose(input);
	return 0;
}

void load()
{
	if((input = fopen("article.txt", "r")) == NULL)
	{
		perror("ERROR");
	}
	int i = 0, j = 0, flag = 0;
	char temp;
	while(feof(input) == 0)
	{
		temp = fgetc(input);
		if(isalpha(temp) != 0)
		{
			if(flag == 0)
			{
				i++;
				flag = 1;
			}
			books[i].word[j++] = tolower(temp);
		}
		else
		{
			if(flag == 1)
			{
				books[i].word[j] = '\0';
				books[i].count = 1;
				j = 0;
				flag = 0;
			}
		}
	}
	if(flag == 1)
	{
		books[i].word[j] = '\0';
		books[i].count = 1;
	}
	count_i = i;
}

void func()
{
	int i, j;
	for(i = 1; i <= count_i; i++)
	{
		for(j = 1; i + j <= count_i; j++)
		{
			if(strcmp(books[i].word, books[i + j].word) == 0)
			{
				books[i].count += books[i + j].count;
				books[i + j].count = 0;
			}
		}
	}
	qsort(books, count_i + 1, sizeof(books[0]), cmp);
}

void print()
{
	int i, j;
	for(i = 1; i <= count_i + 1; i++)
	{
		if(books[i].count != 0)
		{
			for(j = 0; j < strlen(books[i].word); j++)
				printf("%c", books[i].word[j]);
			printf(" %d\n", books[i].count);
		}
	}
}


int cmp(const void *a, const void *b)
{
	if(strcmp((*(_books *)a).word, (*(_books *)b).word) >= 0)
		return 1;
	else
		return -1;
}

