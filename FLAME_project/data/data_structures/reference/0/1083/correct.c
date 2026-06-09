#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
char s[100];
void work();
void expand(int i);
int fun(char a, char b);
int main()
{

  scanf("%s", s);
  work();
  return 0;
}

void work()
{
  int i, len;
  len = strlen(s);
  for (i = 0; i < len; i++)
  {
    if (s[i + 1] == '-' && i + 2 < len)
    {

      expand(i);
      i++;
    }
    else
    {
      printf("%c", s[i]);
    }
  }
}

void expand(int i)
{
  if (fun(s[i], s[i + 2]))
  {
    char a;
    for (a = s[i]; a < s[i + 2]; a++)
    {
      printf("%c", a);
    }
  }
  else
  {
    printf("%c-", s[i]);
  }
}

int fun(char a, char b)
{
  if (b > a)
  {
    if ((islower(a) != 0 && islower(b) != 0) || (isupper(a) != 0 && isupper(b) != 0) || (isdigit(a) != 0 && isdigit(b) != 0))
    {
      return 1;
    }
  }
  return 0;
}
