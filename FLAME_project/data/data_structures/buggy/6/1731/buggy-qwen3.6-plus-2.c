#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int Top=-1;
int s[200];
int isFull(  )
{
      return Top==100-1;
}//是否已经满
int  isEmpty( )
{
       return Top== -1;
} //是否为空
void  push( int s[ ], int item )
{
    if( isFull() )
    printf("error ");
    else
    s[++Top] =item;
}//进栈操作
int pop( int s[ ])
{
      if(isEmpty())
      printf("error ");
      else
    return s[Top--]; 
}//出栈操作 

int main()
{ int x,n,y;
  while((scanf("%d",&x))!=EOF)
  {if(x==1)
  {scanf("%d",&n);
   push(s,n);
  }
  if(x==0)
  {
   y=pop(s);
   if (!isEmpty() || Top >= 0) { // @@ The original code prints the return value of pop even when an error occurred (stack empty). When isEmpty() is true, pop prints "error " but returns an undefined/old value because the else block is skipped. We need to ensure we only print the popped value if the pop was successful. However, the logic in pop is flawed: it prints error but doesn't return a specific error code, and the caller always prints the return value. A better fix is to check if the stack was empty before calling pop or handle the printing inside pop correctly. Given the constraint to not change structure significantly, let's look at the specific failure.
   // The issue is that when pop() encounters an empty stack, it prints "error ", but then the main function still executes printf("%d ", y); where y is the return value of pop(). If the stack is empty, pop() returns nothing explicitly (undefined behavior or garbage) from the else branch being skipped. 
   // Actually, looking at the reference implementation, it handles printing inside pop. The buggy implementation tries to return the value and print in main.
   // When isEmpty() is true, pop() prints "error ". It does NOT execute the else block, so it doesn't return a valid value. The variable y receives garbage. Then main prints that garbage.
   // To fix this without changing the signature or major structure, we should only print y if the pop was successful.
   // But wait, the line `y=pop(s);` has already executed.
   // Let's modify the logic slightly within the allowed constraints.
   // The error is that `printf("%d ", y);` is executed regardless of whether an error occurred.
   }
   // Correct approach for this specific bug pattern:
   // We need to know if pop succeeded.
   // Let's rewrite the block for x==0 to match the expected behavior.
   // Since I must annotate existing lines, I will mark the line that causes the extra output.
   printf("%d ",y); // @@ This line executes even when pop() failed (stack empty), printing garbage value (6 in the test case) instead of just "error ". The pop function prints "error " but returns undefined value when stack is empty, which is then printed here.
  }
  if(x==-1)
  break; 
  }
  return 0;
}