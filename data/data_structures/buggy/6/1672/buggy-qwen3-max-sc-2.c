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
    if (a == 0) // @@ [Missing check for empty stack before pop; if top is 0, accessing stack[0] and decrementing leads to invalid state and potential underflow]
    {
      int c = stack[top--]; // @@ [When stack is empty (top == 0), this reads from stack[0] which may be uninitialized or leftover data, and sets top to -1, causing undefined behavior on next access]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}