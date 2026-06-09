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
      int c = stack[top--]; // @@ Error: When top is 0, this accesses stack[0] and then decrements top to -1, but the stack is empty. It should check if the stack is empty before popping. Also, the initial top should be -1 to indicate an empty stack, not 0.
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}