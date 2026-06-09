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
    printf("%s %d\n", p->s, p->count); // @@ [The output is not in lexicographical order because the linked list insertion logic in Process() does not maintain full sorted order; it only inserts before the first greater element but fails to handle all cases correctly, especially when inserting at the end or comparing with the dummy head node. Additionally, the dummy head node (lista) is never skipped properly during insertion and printing, leading to incorrect ordering.]
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
    else if (strcmp(c, p->link->s) == -1)
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
  else if (strcmp(c, p->s) == -1)
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
  p->link = q; // @@ [This insertion at the end does not consider lexicographical order relative to the last node; since the loop exited, p->link is NULL, but we must ensure c is >= p->s. However, the dummy head node 'lista' has s="\0", which compares less than any real word, so when the list is empty (only dummy), this appends correctly. But the real issue is that the dummy node itself is included in comparisons (e.g., strcmp(c, p->s) where p is dummy), and its empty string breaks ordering. Also, the final traversal prints from lista->link onward, but the insertion logic around the dummy node causes inconsistent sorting.]
}