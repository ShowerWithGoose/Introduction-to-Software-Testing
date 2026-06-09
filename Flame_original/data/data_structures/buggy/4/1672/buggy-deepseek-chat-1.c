#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Words
{
  char s[300];
  int count;
  struct Words *link;
} words;
words *lista;
void Process(char c[300]);
int main()
{
  FILE *in = fopen("article.txt", "r");
  char c[300];
  lista = (words *)malloc(sizeof(words));
  lista->link = NULL;
  lista->s[0] = '\0';
  lista->count = 0;
  char d[2];
  int i = 0;
  while (fgets(d, 2, in) != NULL)
  {
    if ((d[0] <= 'z' && d[0] >= 'a') || (d[0] <= 'Z' && d[0] >= 'A'))
    {
      c[i++] = tolower(d[0]);
    }
    else if (strlen(c) != 0)
    {
      c[i] = '\0';
      Process(c);
      c[0] = '\0';
      i = 0;
    }
  }
  c[i] = '\0';
  if (c[0] != '\0')
  {
    Process(c);
  }
  words *p = lista;
  while (p->link != NULL)
  {
    p = p->link;
    // if ((p->s[0] <= 'z' && p->s[0] >= 'a') || (p->s[0] >= 'A' && p->s[0] <= 'Z'))
    // {
    //   printf("%s %d\n", p->s, p->count);
    // }
    printf("%s %d\n", p->s, p->count);
  }
  return 0;
}
void Process(char c[300])
{
  words *p;
  p = lista;
  while (p->link != NULL)
  {
    if (strcmp(c, p->link->s) == 0)
    {
      p->link->count++;
      return;
    }
    else if (strcmp(c, p->link->s) == -1) // @@ [strcmp returns negative, not necessarily -1; should use < 0]
    {
      words *q = (words *)malloc(sizeof(words));
      q->count = 0;
      int i = 0;
      for (; i < strlen(c); i++)
      {
        q->s[i] = c[i];
      }
      q->s[i] = '\0';
      q->count++;
      q->link = p->link;
      p->link = q;
      return;
    }
    p = p->link;
  }
  if (strcmp(c, p->s) == 0)
  {
    p->count++;
    return;
  }
  else if (strcmp(c, p->s) == -1) // @@ [strcmp returns negative, not necessarily -1; should use < 0]
  {
    words *q = (words *)malloc(sizeof(words));
    q->count = 0;
    int i = 0;
    for (; i < strlen(c); i++)
    {
      q->s[i] = c[i];
    }
    q->s[i] = '\0';
    q->count++;
    q->link = p->link;
    p->link = q;
    return;
  }
  words *q = (words *)malloc(sizeof(words));
  q->count = 0;
  int i = 0;
  for (; i < strlen(c); i++)
  {
    q->s[i] = c[i];
  }
  q->s[i] = '\0';
  q->count++;
  q->link = NULL;
  p->link = q;
}