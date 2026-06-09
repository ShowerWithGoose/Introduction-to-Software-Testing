#include <stdio.h>
int main()
{
  int stack[101];
  int top = 0; // @@ [Should be initialized to -1 to match push/pop logic, or adjust pop operation accordingly]
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
      int c = stack[top--]; // @@ [Should decrement top before accessing (--top) and add empty stack check before pop]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}