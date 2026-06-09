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
    if (a == 0) // @@ [This should be 'else if' to avoid checking pop operation after a push; also, no check for empty stack before popping]
    {
      int c = stack[top--]; // @@ [If stack is empty (top == 0), this accesses stack[-1] which is invalid and causes undefined behavior]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}