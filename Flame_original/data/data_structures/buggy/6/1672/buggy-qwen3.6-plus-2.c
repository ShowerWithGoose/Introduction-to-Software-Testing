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
        scanf("%d", &a); // @@ Incorrectly reads the next operation code instead of consuming the integer value to be pushed, causing input stream desynchronization.
        continue;
      }
      scanf("%d", &item);
      stack[top++] = item;
    }
    if (a == 0)
    {
      int c = stack[top--]; // @@ Missing check for empty stack (top == 0) before popping, which fails to output "error" on underflow and may cause undefined behavior.
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}