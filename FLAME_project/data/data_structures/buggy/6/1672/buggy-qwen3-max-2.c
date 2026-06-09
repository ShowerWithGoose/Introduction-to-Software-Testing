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
    if (a == 0)
    {
      if (top == 0) // @@ [Attempting to pop from an empty stack without checking, leading to undefined behavior and wrong output]
      {
        printf("error ");
      }
      else
      {
        int c = stack[--top]; // @@ [The original code uses post-decrement (top--), which accesses stack[top] before decrementing, but since top points to the next empty slot, it should use pre-decrement (--top) to access the last valid element. However, more fundamentally, the code lacks an empty-stack check before popping.]
        printf("%d ", c);
      }
    }
    scanf("%d", &a);
  }
  return 0;
}