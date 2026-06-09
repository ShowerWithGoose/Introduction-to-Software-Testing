#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int translate(char s[200], int ss[200]);
int work(int ss[200], int sss[200], int len);
int fun1(char op);
int fun2(char op);
char *gets(char *_Buffer);

int main()
{
  char s[200];
  int ss[200], sss[200];
  int len;
  gets(s);
  len = translate(s, ss);
  printf("%d", work(ss, sss, len));
  return 0;
}

int translate(char s[200], int ss[200])
{
  int i, j, k, lens, lenss, sum;
  lens = strlen(s);
  for (i = 0; i < lens; i++)
  {
    if (s[i] == '=')
    {
      lens = i;
      break;
    }
  }
  j = 0;
  for (i = 0; i < lens; i++)
  {
    if (s[i] != ' ')
    {
      if (isdigit(s[i]))
      {
        k = i;
        sum = 0;
        for (; isdigit(s[k]); k++)
        {
          s[k] = s[k] - '0';
          sum = sum * 10 + s[k];
        }
        ss[j++] = sum;
        i = k - 1;
        // printf("%d\n", ss[j - 1]);
      }
      else
      {
        ss[j++] = s[i];
        // printf("%d\n", ss[j - 1]);
      }
    }
  }
  lenss = j;
  return lenss;
}

int work(int ss[200], int sss[200], int len)
{
  int i, j, ans;
  for (i = 0; i < len; i++)
  {
    if (fun1(ss[i]))
    {
      ans = ss[i - 1];
      for (j = i - 1; j < len; j += 2)
      {
        if (fun1(ss[j + 1]) == 1)
        {
          ans *= ss[j + 2];
        }
        else if (fun1(ss[j + 1]) == 2)
        {
          ans /= ss[j + 2];
        }
        else
        {
          break;
        }
      }
      // printf("%d %d\n", j, ans);
      ss[i - 1] = ans;
      // printf("i  %d\n", i);
      for (; i <= j; i++)
      {
        ss[i] = '#';
      }
      i = j + 2;
    }
  }
  j = 0;
  for (i = 0; i < len; i++)
  {
    if (ss[i] != '#')
    {
      sss[j++] = ss[i];
      // printf("      %d %c\n", sss[j - 1]);
    }
  }
  // printf("j=%d\n", j);
  ans = sss[0];
  for (i = 2; i < j; i += 2)
  {
    // printf("ans  %d\n", ans);
    if (fun2(sss[i - 1]) == 1)
    {
      ans += sss[i];
    }
    else
    {
      ans -= sss[i];
    }
  }
  return ans;
}

int fun1(char op)
{
  if (op == '*')
  {
    return 1;
  }
  else if (op == '/')
  {
    return 2;
  }
  return 0;
}

int fun2(char op)
{
  if (op == '+')
  {
    return 1;
  }
  else if (op == '-')
  {
    return 2;
  }
  return 0;
}
