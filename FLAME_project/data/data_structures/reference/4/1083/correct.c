#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct
{
  char word[20];
  int num;
} Word;

char file[10000];
Word words[500];

int fun(int len);
int input(FILE *in);
void maoSort(int n);

int main()
{
  FILE *fp;
  int len, cnt;
  fp = fopen("article.txt", "r");
  len = input(fp);
  // printf("%d\n", fun(len));
  cnt = fun(len);
  maoSort(cnt);
  return 0;
}

int fun(int len)
{
  int i, j, k, cnt = 0;

  for (i = 0; i < len; i++)
  {
    if (isalpha(file[i]))
    {
      // printf("bingo\n");
      file[i] = tolower(file[i]);
    }
  }

  for (i = 0; i < len; i++)
  {
    if (isalpha(file[i]))
    {
      // printf("bingo\n");
      j = i;
      for (; j < len; j++)
      {
        if (!isalpha(file[j]))
        {
          break;
        }
      }
      for (k = i; k < j; k++)
      {
        words[cnt].word[k - i] = file[k];
      }
      cnt++;
      i = j;
    }
  }

  return cnt;
}

int input(FILE *in)
{
  int i = 0;
  char ch;
  ch = fgetc(in);
  while (ch != EOF)
  {
    file[i++] = ch;
    ch = fgetc(in);
  }
  // printf("%d",i);
  return i;
}

void maoSort(int n)
{
  int i, j, p = 0;
  Word term;
  for (i = 0; i < n; i++)
  {
    words[i].num = 1;
  }
  for (i = 0; i < n - 1; i++)
  {
    p = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (strcmp(words[j].word, words[j + 1].word) > 0)
      {

        term = words[j];
        words[j] = words[j + 1];
        words[j + 1] = term;
        p = 1;
      }
    }
    if (p == 0)
      break;
  }
  for (i = 0; i < n - 1; i++)
  {
    if (words[i].num < 0)
    {
      continue;
    }
    for (j = i + 1; j < n; j++)
    {
      if (strcmp(words[i].word, words[j].word) == 0)
      {
        words[i].num++;
        words[j].num = -1;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    if (words[i].num > 0)
    {
      printf("%s %d\n", words[i].word, words[i].num);
    }
  }
}
