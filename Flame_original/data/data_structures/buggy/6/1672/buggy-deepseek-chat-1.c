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
    if (a == 0) // @@ This should be else if to avoid processing a after a push operation that reads a new value
    {
      int c = stack[top--]; // @@ top is decremented before checking if stack is empty, causing underflow; also should check top == 0 for empty
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}