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
        scanf("%d", &a); // @@ Incorrectly reads the value to be pushed into 'a' instead of consuming it, causing the next operation code to be misinterpreted.
        continue;
      }
      scanf("%d", &item);
      stack[top++] = item;
    }
    if (a == 0)
    {
      int c = stack[top--]; // @@ Incorrect pop logic: accesses stack[top] (next free slot) instead of stack[--top] (actual top element), and lacks empty stack check (top == 0) which should output "error ".
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}