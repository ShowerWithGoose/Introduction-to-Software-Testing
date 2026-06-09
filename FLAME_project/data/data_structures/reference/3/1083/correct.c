#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
int main()
{
  int cnt = 0, i, j, len;
  char s[110];
  scanf("%s", s);
  len = strlen(s);
  for (i = 0; i < len; i++)
  {
    if (s[i] == '.')
      break;
  }
  if (i > 1)
  {
    printf("%c.", s[0]);
    for (j = 1; j < len; j++)
    {
      if (j != i)
      {
        printf("%c", s[j]);
      }
    }
    printf("e%d", i - 1);
  }
  else
  {
    
    if (s[0] > '0')
    {
      printf("%se0", s);
    }
    else
    {
      for (j = 2; j < len; j++)
      {
        if (s[j] == '0')
        {
          cnt++;
        }
        else
        {
          break;
        }
      }
      if (len - j > 1)
      {
        printf("%c.", s[j++]);
        for (; j < len; j++)
        {
          printf("%c", s[j]);
        }
      }
      else
      {
        printf("%c", s[j]);
      }
      printf("e-%d", cnt+1);
    }
  }
  return 0;
}
