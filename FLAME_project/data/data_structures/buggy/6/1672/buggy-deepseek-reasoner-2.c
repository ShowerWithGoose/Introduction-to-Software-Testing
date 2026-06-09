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
        scanf("%d", &a); // @@ This reads the push item into variable a, causing subsequent input misreading; should always read the item and discard or process correctly.
        continue;
      }
      scanf("%d", &item);
      stack[top++] = item;
    }
    if (a == 0)
    {
      int c = stack[top--]; // @@ Uses post-decrement, accessing wrong index (should be stack[--top]); also lacks empty stack check (should print "error " if top==0) 
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}