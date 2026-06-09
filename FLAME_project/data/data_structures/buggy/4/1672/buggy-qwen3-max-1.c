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
    printf("%s %d\n", p->s, p->count); // @@ [The output is not in lexicographical order because the linked list is not maintained in sorted order during insertion. The Process function inserts new words at the end or before the first greater word, but the initial dummy node and inconsistent comparisons break the ordering. Also, the dummy head node (lista) is never removed from output consideration, though it's skipped due to loop starting at p->link, but its presence complicates logic.]
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
  p->link = q; // @@ [This insertion at the end does not maintain lexicographical order. When a new word is greater than all existing words, it should be appended at the end, which is correct, but the earlier logic comparing with p->s (the dummy head) is flawed because the dummy head's string is empty (""). Comparing any non-empty word with "" using strcmp returns >0, so the final else block runs, which is okay, but the prior check `if (strcmp(c, p->s) == 0)` will never match since p->s is "", so it's harmless but unnecessary. However, the main issue is that the dummy head node complicates insertion logic and may lead to incorrect ordering when inserting words that are less than some but not handled properly due to inconsistent traversal. Additionally, the dummy node itself is never used to store real data, but the comparison against it introduces bugs.]
}