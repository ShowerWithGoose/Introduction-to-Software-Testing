#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
char wsl[10000];
struct cao
{
  ll cao, sb;
} c[1000] = {0}, n[1000] = {0}, m[1000];
int cmp(const void *c, const void *n)
{
  struct cao *aa = (struct cao *)c;
  struct cao *bb = (struct cao *)n;
  return (((aa->sb) > (bb->sb)) ? -1 : 1);
}
int Pre(struct cao m[])
{
  int len = strlen(wsl), k = 1;
  for (int i = 0; i < len; ++i)
  {
    // printf("*");
    if (wsl[i] == ' ')
      continue;
    ll t = 0;
    while (wsl[i] >= '0' && wsl[i] <= '9')
      t = t * 10ll + wsl[i] - '0', ++i;
    if (m[k].cao == 0)
      m[k].cao = t;
    else
      m[k].sb = t, ++k;
  }
  return k - 1;
}
int main()
{
  int n1, n2;
  gets(wsl);
  n1 = Pre(c);
  gets(wsl);
  n2 = Pre(n);
  // printf("%d %d", n, m);
  for (int i = 1; i <= n1; ++i)
    for (int j = 1; j <= n2; ++j)
    {
      m[(i - 1) * n2 + j].cao = c[i].cao * n[j].cao;
      m[(i - 1) * n2 + j].sb = c[i].sb + n[j].sb;
    }
  qsort(m + 1, n1 * n2, sizeof(m[0]), cmp);
  ll cao = m[1].cao, sb = m[1].sb;
  for (int i = 1; i <= n1 * n2 - 1; ++i)
  {
    if (m[i].sb == m[i + 1].sb)
      cao += m[i + 1].cao;
    else
    {
      printf("%lld %lld ", cao, sb);
      cao = m[i + 1].cao;
      sb = m[i + 1].sb;
    }
  }
  printf("%lld %lld", cao, sb);
  return 0;
}
