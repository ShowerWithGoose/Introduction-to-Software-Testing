#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
char s[10000];
struct cao
{
  ll xi, zhi;
} a[1000] = {0}, b[1000] = {0}, c[1000];
int cmp(const void *a, const void *b)
{
  struct cao *aa = (struct cao *)a;
  struct cao *bb = (struct cao *)b;
  return (((aa->zhi) > (bb->zhi)) ? -1 : 1);
}
int Pre(struct cao c[])
{
  int len = strlen(s), k = 1;
  for (int i = 0; i < len; ++i)
  {
    // printf("*");
    if (s[i] == ' ')
      continue;
    ll t = 0;
    while (s[i] >= '0' && s[i] <= '9')
      t = t * 10ll + s[i] - '0', ++i;
    if (c[k].xi == 0)
      c[k].xi = t;
    else
      c[k].zhi = t, ++k;
  }
  return k - 1;
}
int main()
{
  int n, m;
  gets(s);
  n = Pre(a);
  gets(s);
  m = Pre(b);
  // printf("%d %d", n, m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      c[(i - 1) * m + j].xi = a[i].xi * b[j].xi;
      c[(i - 1) * m + j].zhi = a[i].zhi + b[j].zhi;
    }
  qsort(c + 1, n * m, sizeof(c[0]), cmp);
  ll xi = c[1].xi, zhi = c[1].zhi;
  for (int i = 1; i <= n * m - 1; ++i)
  {
    if (c[i].zhi == c[i + 1].zhi)
      xi += c[i + 1].xi;
    else
    {
      printf("%lld %lld ", xi, zhi);
      xi = c[i + 1].xi;
      zhi = c[i + 1].zhi;
    }
  }
  printf("%lld %lld", xi, zhi);
  return 0;
}
