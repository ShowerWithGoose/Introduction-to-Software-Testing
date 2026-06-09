#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
int n;
int ans[20], bin[20];
void print();
void dfs(int k);
int main()
{
  scanf("%d", &n);
  memset(bin, 0, sizeof(bin));
  dfs(1);
  return 0;
}

void print()
{
  int i;
  for (i = 1; i <= n; i++)
  {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

void dfs(int k)
{
  int i;
  if (k > n)
  {
    print();
  }
  else
  {
    for (i = 1; i <= n; i++)
    {
      if (bin[i] == 0)
      {
        ans[k] = i;
        bin[i] = 1;
        dfs(k + 1);
        bin[i] = 0;
      }
    }
  }
}


