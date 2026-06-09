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
        scanf("%d", &a); // @@ [Incorrectly reads the item integer into a, causing misalignment of subsequent input. It should read into a temporary variable or into item and then discard.]
        continue;
      }
      scanf("%d", &item);
      stack[top++] = item;
    }
    if (a == 0)
    {
      int c = stack[top--]; // @@ [Uses post-decrement, which accesses the next empty slot rather than the top element (should be --top). Also missing empty-stack check that would print "error".]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}