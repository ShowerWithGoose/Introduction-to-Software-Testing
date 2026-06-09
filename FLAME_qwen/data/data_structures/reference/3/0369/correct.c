#include <stdio.h>
#include <string.h>
int main()
{
  char s[1000];
  scanf("%s", s);
  int len = strlen(s), bj = -1, num = 0;
  for (int i = 0; i < len; ++i)
  {
    if (s[i] == '.')
      bj = i;
  }
  if (bj == 1 && s[0] == '0')
  {
    for (int i = len - 1; i >= 0; --i)
    {
      if (s[i] >= '1' && s[i] <= '9')
      {
        bj = i;
        num++;
        // break;
      }
    }

    if (num > 1)
      printf("%c.", s[bj]);
    else
      printf("%c", s[bj]);
    for (int i = bj + 1; i < len; ++i)
      printf("%c", s[i]);
    printf("e-%d", bj - 1);
  }
  else
  {
    printf("%c.", s[0]);
    for (int i = 1; i < len; ++i)
    {
      if (s[i] != '.')
        printf("%c", s[i]);
    }
    printf("e%d", bj - 1);
  }
  return 0;
}
