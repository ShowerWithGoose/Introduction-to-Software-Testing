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
    if (a == 0) // @@ [Missing check for empty stack before pop; if top is 0, stack is empty, but code still tries to pop, leading to undefined behavior or incorrect output]
    {
      int c = stack[top--]; // @@ [When stack is empty (top == 0), this accesses stack[0] and decrements top to -1, which is invalid]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}