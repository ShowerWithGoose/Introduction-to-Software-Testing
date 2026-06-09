#include <stdio.h>
int vst[15] = {0}, shu[15] = {0}, n;
void dfs(int x)
{
  if (x == n + 1)
  {
    for (int i = 1; i <= n; ++i)
      printf("%d ", shu[i]);
    printf("\n");
    return;
  }
  for (int i = 1; i <= n; ++i)
  {
    if (!vst[i])
    {
      vst[i] = 1;
      shu[x] = i;
      // printf("%d ", i);
      dfs(x + 1);
      vst[i] = 0;
    }
  }
}
int main()
{
  // int n;
  scanf("%d", &n);
  dfs(1);
  return 0;
}
