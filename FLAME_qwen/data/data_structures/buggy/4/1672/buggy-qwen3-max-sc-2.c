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
  FILE *in = fopen("article.txt", "r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgets on a NULL pointer causes undefined behavior (likely crash). The program does not check if 'in' is NULL.]
  char c[300];
  lista = (words *)malloc(sizeof(words));
  lista->link = NULL;
  lista->s[0] = '\0';
  lista->count = 0;
  char d[2];
  int i = 0;
  while (fgets(d, 2, in) != NULL) // @@ [Using fgets with size=2 reads one character at a time plus null terminator, which is inefficient and may mishandle consecutive non-alphabetic characters. More critically, if the file is empty or in is NULL (from failed fopen), this leads to undefined behavior. Also, fgets reads newline as part of input, which is not handled correctly for word boundaries.]
  {
    if ((d[0] <= 'z' && d[0] >= 'a') || (d[0] <= 'Z' && d[0] >= 'A'))
    {
      c[i++] = tolower(d[0]);
    }
    else if (strlen(c) != 0) // @@ [strlen(c) is used to check if c is non-empty, but c may not be null-terminated before this point if only raw characters were appended without setting a '\0'. This leads to undefined behavior.]
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
    printf("%s %d\n", p->s, p->count); // @@ [The initial dummy node 'lista' has s[0]='\0' and count=0. If no words are processed, this loop won't print it, but if words are inserted after, the dummy node is skipped correctly. However, if the file ends without triggering the final word flush properly (e.g., last character is alphabetic but EOF follows), the last word might be printed correctly. But the real issue is that the linked list insertion logic in Process() does not maintain lexicographical order correctly in all cases, especially when inserting at the end or comparing with the dummy head node. Additionally, the dummy node itself should not be printed, which is handled, but the ordering logic is flawed.]
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
    else if (strcmp(c, p->link->s) == -1) // @@ [This condition assumes that if c < p->link->s, we should insert before p->link. However, the loop starts from the dummy head, and the comparison logic fails when the list has only the dummy node or when inserting a word that is greater than all existing words. Also, strcmp returning -1 is not the only way c < p->link->s; better to use < 0. But more critically, the insertion at the correct sorted position is not guaranteed because the loop breaks early and doesn't traverse fully when needed.]
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
  if (strcmp(c, p->s) == 0) // @@ [Here, p points to the last node (which could be the dummy head if list is empty). Comparing with p->s (dummy's s, which is "") will never match a real word, so this condition is mostly useless. Also, the dummy node's s is "", so any real word c will have strcmp(c, "") > 0, so this block is rarely entered.]
  {
    p->count++;
    return;
  }
  else if (strcmp(c, p->s) == -1) // @@ [Since p->s is "" (from dummy node initialization), strcmp(c, "") is always > 0 for any non-empty c, so this condition never triggers. Thus, insertion after the last node is handled by the next block, but the logic is confused due to the dummy node.]
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
  words *q = (words *)malloc(sizeof(words)); // @@ [This block inserts at the end, but since the list is supposed to be sorted, inserting at the end without checking order violates lexicographical output requirement. The earlier logic failed to insert in correct position, so this fallback breaks sorting.]
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