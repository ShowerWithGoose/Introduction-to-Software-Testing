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
    if (a == 0) // @@ [Error: This should be 'else if' instead of 'if'. When a == 1 and the stack is full, after reading the next value into 'a' and continuing, 'a' might be 0, causing an unintended pop from an empty or incorrect stack state. Additionally, when a == 1 and the push succeeds, 'a' is still 1 after the push, so the subsequent 'if (a == 0)' check is unnecessary but harmless; however, the main issue is the missing check for empty stack before popping.]
    {
      int c = stack[top--]; // @@ [Error: No check for empty stack (top == 0) before popping. If the stack is empty, this accesses stack[-1] and decrements top to -1, causing undefined behavior. The program should print "error " and skip the pop when the stack is empty.]
      printf("%d ", c);
    }
    scanf("%d", &a);
  }
  return 0;
}