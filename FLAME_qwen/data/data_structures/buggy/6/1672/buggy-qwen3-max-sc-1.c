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
        scanf("%d", &a);
        continue;
      }
      scanf("%d", &item);
      stack[top++] = item;
    }
    if (a == 0) // @@ [Missing check for empty stack before pop; should verify top > 0 before accessing stack[top--]]
    {
      int c = stack[top--]; // @@ [If top is 0 (empty stack), this accesses stack[0] and decrements top to -1, causing undefined behavior and missing "error" output]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}