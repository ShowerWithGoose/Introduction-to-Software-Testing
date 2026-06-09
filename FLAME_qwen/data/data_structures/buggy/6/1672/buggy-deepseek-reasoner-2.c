#include <stdio.h>
int main()
{
  int stack[101];
  int top = 0;
  int a;
  int item;
  scanf("%d", &a);
  while (a != -1)
  {
    if (a == 1)
    {
      if (top == 100)
      {
        printf("error ");
        scanf("%d", &a); // @@ Reading the value into 'a' will treat it as the next operation; should read into a dummy variable.
        continue;
      }
      scanf("%d", &item);
      stack[top++] = item;
    }
    if (a == 0)
    {
      int c = stack[top--]; // @@ Incorrect stack access; should use '--top' to get the current top element. Also missing empty-stack check.
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}