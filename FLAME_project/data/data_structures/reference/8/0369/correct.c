#include <stdio.h>
#include <string.h>
int n, m, q;
int a[105][105] = {0}, vst[105] = {0};

void dfs(int x)
{
  printf("%d ", x);
  vst[x] = 1;
  for (int i = 0; i < n; i++)
    if (a[x][i] == 1 && vst[i] == 0)
    {
      dfs(i);
    }
}

void bfs(int x)
{
  int q[105] = {0}, head = 0, tail = 0;
  vst[x] = 1;
  q[tail] = x;
  while (head <= tail)
  {
    int t = q[head++];
    printf("%d ", t);
    for (int i = 0; i < n; i++)
      if (a[t][i] == 1 && vst[i] == 0)
      {
        vst[i] = 1;
        q[++tail] = i;
      }
  }
  putchar('\n');
}

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    a[y][x] = a[x][y] = 1;
  }
  scanf("%d", &q);
  dfs(0);
  putchar('\n');
  memset(vst, 0, sizeof(vst));
  bfs(0);
  memset(vst, 0, sizeof(vst));
  for (int i = 0; i < n; ++i)
    a[q][i] = 0, a[i][q] = 0;
  dfs(0);
  putchar('\n');
  memset(vst, 0, sizeof(vst));
  bfs(0);
}
