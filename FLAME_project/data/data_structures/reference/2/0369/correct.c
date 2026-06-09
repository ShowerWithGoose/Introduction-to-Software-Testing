#include <stdio.h>
#include <string.h>
char st[1000];
int cal(int a, char mark, int b)
{
  if (mark == '+')
    return a + b;
  if (mark == '-')
    return a - b;
  if (mark == '*')
    return a * b;
  if (mark == '/')
    return a / b;
  else
    return 1;
}
int isnum(int left, int right)
{
  int i, data = 0;
  for (int i = left; i <= right; ++i)
  {
    if (st[i] >= '0' && st[i] <= '9')
      data = data * 10 + st[i] - '0';
    else
      return -1;
  }
  return data;
}
int findlow(int left, int right)
{
  int i, k = -1;
  for (int i = right; i >= left; --i)
  {
    if (st[i] >= '0' && st[i] <= '9')
      continue;
    if (st[i] == '+' || st[i] == '-')
      return i;
    if ((st[i] == '*' || st[i] == '/') && k == -1)
      k = i;
  }
  return k;
}
int tree(int left, int right)
{
  int tmp, l1, l2, p;
  tmp = isnum(left, right);
  if (tmp != -1)
    return tmp;
  p = findlow(left, right);
  l1 = tree(left, p - 1);
  l2 = tree(p + 1, right);
  // printf("%d %d    ", p, cal(l1, st[p], l2));
  return cal(l1, st[p], l2);
}
int main()
{
  char s[1000];
  gets(s);
  int len = strlen(s), k = 0;
  for (int i = 0; i < len; ++i)
  {
    if (s[i] == ' ' || s[i] == '=')
      continue;
    st[k++] = s[i];
  }
  // printf("%s", st);
  // printf("%d", strlen(st));
  printf("%d", tree(0, strlen(st) - 1));
  return 0;
}
