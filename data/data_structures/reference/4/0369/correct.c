#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000][1000];
char ss[1000][25] = {0};
int cmp(const void *a, const void *b)
{
  return strcmp((char *)a, (char *)b);
}
int main()
{
  FILE *in;
  in = fopen("article.txt", "r");
  int n = 0, m = 0, bj = 0;
  while (fgets(s[n], 1000, in) != NULL)
    n++;
  for (int i = 0; i < n; ++i)
  {
    int len = strlen(s[i]), k = 0;
    for (int j = 0; j < len; ++j)
    {
      if (s[i][j] >= 'a' && s[i][j] <= 'z' || s[i][j] >= 'A' && s[i][j] <= 'Z')
      {
        if (s[i][j] >= 'a' && s[i][j] <= 'z')
          ss[m][k++] = s[i][j];
        else
          ss[m][k++] = s[i][j] + 32;
        bj = 1;
      }
      else
      {
        if (bj)
        {
          m++;
          k = 0;
          bj = 0;
        }
      }
    }
  }
  // printf("%d", m);
  qsort(ss, m, sizeof(ss[0]), cmp);
  int k = 1;
  for (int i = 0; i < m - 1; ++i)
  {
    if (strcmp(ss[i], ss[i + 1]) == 0)
      k++;
    else
    {
      printf("%s %d\n", ss[i], k);
      k = 1;
    }
  }
  printf("%s %d", ss[m - 1], k);
  return 0;
}
