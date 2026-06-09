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
        int c = stack[--top]; // @@ [Using post-decrement `top--` would access invalid index when stack is empty; also, should decrement before accessing in 0-based top-as-count model]
        printf("%d ", c);
      }
    }
    scanf("%d", &a);
  }
  return 0;
}