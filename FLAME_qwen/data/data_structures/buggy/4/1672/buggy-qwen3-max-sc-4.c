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
  FILE *in = fopen("article.txt", "r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgets will cause undefined behavior. The program should check if 'in' is NULL before proceeding.]
  char c[300];
  lista = (words *)malloc(sizeof(words));
  lista->link = NULL;
  lista->s[0] = '\0';
  lista->count = 0;
  char d[2]; // @@ [Using fgets(d, 2, in) reads only one character at a time plus null terminator, which is inefficient and error-prone. More critically, this approach fails to correctly detect word boundaries when non-alphabetic characters appear because it processes input byte-by-byte without handling EOF properly after the last word.]
  int i = 0;
  while (fgets(d, 2, in) != NULL) // @@ [This loop condition fails to handle the case where the file ends with a word not followed by a non-letter. The final word may not be processed correctly because the loop exits before triggering the else-if clause that calls Process(c). Additionally, fgets on a 2-char buffer is unconventional and fragile.]
  {
    if ((d[0] <= 'z' && d[0] >= 'a') || (d[0] <= 'Z' && d[0] >= 'A'))
    {
      c[i++] = tolower(d[0]);
    }
    else if (strlen(c) != 0) // @@ [Using strlen(c) here is incorrect because 'c' is not guaranteed to be null-terminated at this point. The array 'c' is built by direct assignment without inserting '\0' until later, so strlen may read uninitialized memory, leading to undefined behavior.]
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
    printf("%s %d\n", p->s, p->count); // @@ [The output order may not be lexicographical because the insertion logic in Process() does not maintain a fully sorted list in all cases. Specifically, when inserting at the end, it doesn't compare against all existing nodes correctly, potentially breaking sort order. Also, the initial dummy node 'lista' has an empty string with count 0, which should not be printed, but the printing loop skips it correctly; however, if any real word compares less than "" (which none do), logic could break.]
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
    else if (strcmp(c, p->link->s) == -1) // @@ [This condition assumes that if c < p->link->s, we should insert before it, which is correct for maintaining order. However, the logic does not handle the case where multiple nodes exist and the new word belongs between two existing nodes correctly in all paths, especially due to early returns. Also, comparing with == -1 is not portable; strcmp can return any negative value, not necessarily -1.]
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
  if (strcmp(c, p->s) == 0) // @@ [This compares with the dummy head node 'lista', which was initialized with an empty string. Since no real word equals "", this condition is effectively dead code. But more importantly, the dummy node should not participate in comparisons—it breaks the design. The real list starts at lista->link, so this comparison is logically flawed.]
  {
    p->count++;
    return;
  }
  else if (strcmp(c, p->s) == -1) // @@ [Same issue: comparing against dummy node's empty string. Also, using == -1 instead of < 0 is non-portable.]
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