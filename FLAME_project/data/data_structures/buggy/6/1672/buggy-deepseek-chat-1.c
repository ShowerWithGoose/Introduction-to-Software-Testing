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
      int c = stack[top--]; // @@ Error: When the stack is empty (top == 0), this line accesses stack[0] which is invalid and does not check for underflow. It should check if top == 0 and print "error " instead of popping.
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}