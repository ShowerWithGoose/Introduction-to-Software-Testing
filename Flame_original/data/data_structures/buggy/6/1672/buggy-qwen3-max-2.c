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
      int c = stack[top--]; // @@ [If stack is empty (top == 0), this accesses stack[0] then sets top to -1, which is invalid and causes undefined behavior]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}